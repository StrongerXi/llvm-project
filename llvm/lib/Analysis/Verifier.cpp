//===-- Verifier.cpp - Implement the Module Verifier -------------*- C++ -*-==//
//
// This file defines the method verifier interface, that can be used for some
// sanity checking of input to the system.
//
// Note that this does not provide full 'java style' security and verifications,
// instead it just tries to ensure that code is well formed.
//
//  . There are no duplicated names in a symbol table... ie there !exist a val
//    with the same name as something in the symbol table, but with a different
//    address as what is in the symbol table...
//  . Both of a binary operator's parameters are the same type
//  . Only PHI nodes can refer to themselves
//  . All of the constants in a switch statement are of the correct type
//  . The code is in valid SSA form
//  . It should be illegal to put a label into any other type (like a structure)
//    or to return one. [except constant arrays!]
//  . Right now 'add bool 0, 0' is valid.  This isn't particularly good.
//  . Only phi nodes can be self referential: 'add int 0, 0 ; <int>:0' is bad
//  . All other things that are tested by asserts spread about the code...
//  . All basic blocks should only end with terminator insts, not contain them
//  . All methods must have >= 1 basic block
//  . Verify that none of the Def getType()'s are null.
//  . Method's cannot take a void typed parameter
//  . Verify that a method's argument list agrees with it's declared type.
//  . Verify that arrays and structures have fixed elements: No unsized arrays.
//
//===----------------------------------------------------------------------===//

#include "llvm/Analysis/Verifier.h"

#include "llvm/BasicBlock.h"
#include "llvm/Method.h"
#include "llvm/Module.h"
#include "llvm/Type.h"

static bool verify(const BasicBlock *BB, std::vector<std::string> &ErrorMsgs) {
  bool Bad = false;
  if (BB->getTerminator() == 0) {
    ErrorMsgs.push_back("Basic Block does not have terminator!");
    Bad = true;
  }
  return Bad;
}

bool verify(const Method *M, std::vector<std::string> &ErrorMsgs) {
  bool Bad = false;
  for (const BasicBlock* BB : M->getBasicBlocks()) {
    Bad |= verify(BB, ErrorMsgs);
  }
  return Bad;
}

bool verify(const Module *C, std::vector<std::string> &ErrorMsgs) {
  assert(Type::FirstDerivedTyID - 1 < sizeof(long) * 8 &&
         "Resize ValidTypes table to handle more than 32 primitive types!");
  bool Bad = false;
  for (const Method* M : C->getMethodList()) {
    Bad |= verify(M, ErrorMsgs);
  }
  return Bad;
}
