//===- DCE.cpp - Code to perform dead code elimination --------------------===//
//
// This file implements dead code elimination and basic block merging.
//
// Specifically, this:
//   * removes definitions with no uses (including unused constants)
//   * removes basic blocks with no predecessors
//   * merges a basic block into its predecessor if there is only one and the
//     predecessor only has one successor.
//
// TODO: This should REALLY be recursive instead of iterative.  Right now, we
// scan linearly through values, removing unused ones as we go.  The problem is
// that this may cause other earlier values to become unused.  To make sure that
// we get them all, we iterate until things stop changing.  Instead, when
// removing a value, recheck all of its operands to see if they are now unused.
// Piece of cake, and more efficient as well.
//
//===----------------------------------------------------------------------===//

#include "llvm/BasicBlock.h"
#include "llvm/ConstantPool.h"
#include "llvm/Method.h"
#include "llvm/Module.h"
#include "llvm/Opt/AllOpts.h"
#include "llvm/iTerminators.h"

namespace {

struct ConstPoolDCE {
  static bool isDCEable(const Value *) { return true; }
};

struct BasicBlockDCE {
  static bool isDCEable(const Instruction *I) {
    return !I->isTerminator() && !I->hasSideEffects();
  }
};

template <class DCEController, class ValueSubclass, class ItemParentType>
bool RemoveUnusedDefs(ValueHolder<ValueSubclass, ItemParentType> &Vals) {
  bool Changed = false;
  for (auto DI = Vals.begin(); DI != Vals.end();) {
    // Look for un"used" definitions...
    const auto *val = *DI;
    if (val->use_empty() && DCEController::isDCEable(val)) {
      delete Vals.remove(DI);
      Changed = true;
    } else {
      DI++;
    }
  }
  return Changed;
}

ConstPoolVal *getOrAddNullConstantOfType(ConstantPool &CP, const Type *type) {
  ConstPoolVal *CPV = nullptr;
  ConstantPool::PlaneType *P;
  if (!CP.getPlane(type, P) && !P->empty()) {
    CPV = P->front();
  } else { // We don't have an existing constant to reuse. Just add one.
    CPV = ConstPoolVal::getNullConstant(type);
    CP.insert(CPV);
  }
  return CPV;
}

void ReplaceUsesWithConstant(Instruction *I) {
  auto &CP = I->getParent()->getParent()->getConstantPool();
  auto *CPV = getOrAddNullConstantOfType(CP, I->getType());
  I->replaceAllUsesWith(CPV);
}

bool onlyHasOneSucc(const BasicBlock *BB) {
  // TODO why did Chris use Terminator & unconditional-branch check?
  auto SI = BB->succ_begin();
  return SI != BB->succ_end() && ++SI == BB->succ_end();
}

bool onlyHasOnePred(const BasicBlock *BB) {
  auto PI = BB->pred_begin();
  return PI != BB->pred_end() && ++PI == BB->pred_end() &&
         !BB->hasConstantPoolReferences();
}

bool hasNoPred(const BasicBlock *BB) {
  return BB->pred_begin() == BB->pred_end() && !BB->hasConstantPoolReferences();
}

// except for the first (entry) block
bool removeBBsWithoutPredecessors(Method::BasicBlocksType &BBs) {
  bool Changed = false;
  for (auto BBIt = std::next(BBs.begin()); BBIt != BBs.end(); BBIt++) {
    BasicBlock *BB = *BBIt;
    if (hasNoPred(BB)) {
      while (!BB->getInstList().empty()) {
        auto IIt = BB->getInstList().begin();
        Instruction *I = *IIt;
        // If this instruction is used, replace uses with an arbitrary
        // constant value. Because control flow can't get here, we don't care
        // what we replace the value with. Think uninitialized variable usage.
        if (!I->use_empty())
          ReplaceUsesWithConstant(I);

        // Remove the instruction from the basic block
        delete BB->getInstList().remove(IIt);
      }

      delete BBs.remove(BBIt);
      ++BBIt; // remove puts use on the previous block, we want the next one
      Changed = true;
    }
  }
  return Changed;
}

//    .......
//     \ | /
//      pred (no other successor)
//       |
//       BB  (no other predecessor)
// --->
//    .......
//     \ | /
//       BB  (with pred's instructions at front)
bool mergeBBsIntoSuccessor(Method::BasicBlocksType &BBs) {
  bool Changed = false;
  for (BasicBlock *BB : BBs) {
    if (!onlyHasOnePred(BB)) {
      continue;
    }
    BasicBlock *Pred = *BB->pred_begin();
    if (!onlyHasOneSucc(Pred)) {
      continue;
    }
    Changed = true;

    // Make all branches to the predecessor now point to the successor...
    Pred->replaceAllUsesWith(BB);

    // Move all non-terminator definitions in the predecessor to the successor
    auto TermIter = std::prev(Pred->getInstList().end());
    delete Pred->getInstList().remove(TermIter);
    while (!Pred->getInstList().empty()) {
      auto LastIter = std::prev(Pred->getInstList().end());
      Instruction *Def =
          Pred->getInstList().remove(LastIter); // Remove last inst
      BB->getInstList().push_front(Def);
    }

    // Always inherit predecessors name if it exists...
    if (Pred->hasName()) {
      BB->setName(Pred->getName());
    }

    // Remove basic block from the method...
    BBs.remove(Pred);
    delete Pred;
  }
  return Changed;
}

bool DoDCEPass(Method *M) {
  auto &BBs = M->getBasicBlocks();
  bool Changed = false;

  // Loop through now and remove instructions that have no uses...
  // TODO for faster convergence, use a worklist
  for (BasicBlock *BB : BBs) {
    Changed |= RemoveUnusedDefs<BasicBlockDCE>(BB->getInstList());
  }
  Changed |= removeBBsWithoutPredecessors(BBs);
  Changed |= mergeBBsIntoSuccessor(BBs);
  Changed |= DoRemoveUnusedConstants(M);
  return Changed;
}

} // namespace

// It is possible that we may require multiple passes over the code to fully
// eliminate dead code.  Iterate until we are done.
//
bool DoDeadCodeElimination(Method *M) {
  bool Changed = false;
  while (DoDCEPass(M)) {
    Changed = true;
  }
  return Changed;
}

bool DoRemoveUnusedConstants(SymTabValue *S) {
  bool Changed = false;
  ConstantPool &CP = S->getConstantPool();
  for (auto *plane : CP) {
    Changed |= RemoveUnusedDefs<ConstPoolDCE>(*plane);
  }
  return Changed;
}

bool DoDeadCodeElimination(Module *C) {
  bool Changed = ApplyOptToAllMethods(C, DoDeadCodeElimination);
  while (DoRemoveUnusedConstants(C)) { // TODO global constants in module?
    Changed = true;
  }
  return Changed;
}
