//===-- llvm/ValueHolder.h - Class to hold multiple values -------*- C++ -*--=//
//
// This defines a class that is used as a fancy Definition container.  It is
// special because it helps keep the symbol table of the container method up to
// date with the goings on inside of it.
//
// This is used to represent things like the instructions of a basic block and
// the arguments to a method.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_VALUEHOLDER_H
#define LLVM_VALUEHOLDER_H

#include <vector>
#include "llvm/SymTabValue.h"
#include "llvm/SymbolTable.h"
#include <algorithm>

class SymTabValue;

// ItemParentType ItemParent - I call setParent() on all of my
// "ValueSubclass" items, and this is the value that I pass in.
//
template <class ValueSubclass, class ItemParentType> class ValueHolder {
  // TODO: Should I use a deque instead of a vector?
  std::vector<ValueSubclass *> ValueList;

  ItemParentType *ItemParent;
  SymTabValue *Parent;

  ValueHolder(const ValueHolder &V); // DO NOT IMPLEMENT
public:
  inline ValueHolder(ItemParentType *IP, SymTabValue *parent = 0) {
    assert(IP && "Item parent may not be null!");
    ItemParent = IP;
    Parent = 0;
    setParent(parent);
  }

  inline ~ValueHolder() {
    // The caller should have called delete_all first...
    assert(empty() && "ValueHolder contains definitions!");
    assert(Parent == 0 && "Should have been unlinked from method!");
  }

  inline const SymTabValue *getParent() const { return Parent; }
  inline SymTabValue *getParent() { return Parent; }
  void setParent(SymTabValue *Parent); // Defined in ValueHolderImpl.h

  inline unsigned size() const { return ValueList.size(); }
  inline bool empty() const { return ValueList.empty(); }
  inline const ValueSubclass *front() const { return ValueList.front(); }
  inline ValueSubclass *front() { return ValueList.front(); }
  inline const ValueSubclass *back() const { return ValueList.back(); }
  inline ValueSubclass *back() { return ValueList.back(); }

  //===--------------------------------------------------------------------===//
  // sub-Definition iterator code
  //===--------------------------------------------------------------------===//
  //
  typedef typename std::vector<ValueSubclass *>::iterator iterator;
  typedef typename std::vector<ValueSubclass *>::const_iterator const_iterator;

  inline iterator begin() { return ValueList.begin(); }
  inline const_iterator begin() const { return ValueList.begin(); }
  inline iterator end() { return ValueList.end(); }
  inline const_iterator end() const { return ValueList.end(); }

  void delete_all() { // Delete all removes and deletes all elements
    // TODO: REMOVE FROM END OF VECTOR!!!
    while (begin() != end()) {
      iterator I = begin();
      delete remove(I); // Delete all instructions...
    }
  }

  // ValueHolder::remove(iterator &) this removes the element at the location
  // specified by the iterator, and leaves the iterator pointing to the element
  // that used to follow the element deleted.
  //
  ValueSubclass *remove(iterator &DI); // Defined in ValueHolderImpl.h
  void remove(ValueSubclass *D);       // Defined in ValueHolderImpl.h

  inline void push_front(ValueSubclass *Inst); // Defined in ValueHolderImpl.h
  inline void push_back(ValueSubclass *Inst);  // Defined in ValueHolderImpl.h
};

template <class ValueSubclass, class ItemParentType>
void ValueHolder<ValueSubclass, ItemParentType>::setParent(SymTabValue *P) {
  if (Parent) { // Remove all of the items from the old symbol table..
    SymbolTable *SymTab = Parent->getSymbolTable();
    for (iterator I = begin(); I != end(); I++)
      if ((*I)->hasName())
        SymTab->remove(*I);
  }

  Parent = P;

  if (Parent) { // Remove all of the items from the old symbol table..
    SymbolTable *SymTab = Parent->getSymbolTableSure();
    for (iterator I = begin(); I != end(); I++)
      if ((*I)->hasName())
        SymTab->insert(*I);
  }
}

template <class ValueSubclass, class ItemParentType>
void ValueHolder<ValueSubclass, ItemParentType>::remove(ValueSubclass *D) {
  iterator I(find(begin(), end(), D));
  assert(I != end() && "Value not in ValueHolder!!");
  remove(I);
}

// ValueHolder::remove(iterator &) this removes the element at the location
// specified by the iterator, and leaves the iterator pointing to the element
// that used to follow the element deleted.
//
template <class ValueSubclass, class ItemParentType>
ValueSubclass *
ValueHolder<ValueSubclass, ItemParentType>::remove(iterator &DI) {
  assert(DI != ValueList.end() &&
         "Trying to remove the end of the def list!!!");

  ValueSubclass *i = *DI;
  DI = ValueList.erase(DI);

  i->setParent(0); // I don't own you anymore... byebye...

  // You don't get to be in the symbol table anymore... byebye
  if (i->hasName() && Parent)
    Parent->getSymbolTable()->remove(i);

  return i;
}

template <class ValueSubclass, class ItemParentType>
void ValueHolder<ValueSubclass, ItemParentType>::push_front(
    ValueSubclass *Inst) {
  assert(Inst->getParent() == 0 && "Value already has parent!");
  Inst->setParent(ItemParent);

  // ValueList.push_front(Inst);
  ValueList.insert(ValueList.begin(), Inst);

  if (Inst->hasName() && Parent)
    Parent->getSymbolTableSure()->insert(Inst);
}

template <class ValueSubclass, class ItemParentType>
void ValueHolder<ValueSubclass, ItemParentType>::push_back(
    ValueSubclass *Inst) {
  assert(Inst->getParent() == 0 && "Value already has parent!");
  Inst->setParent(ItemParent);

  ValueList.push_back(Inst);

  if (Inst->hasName() && Parent)
    Parent->getSymbolTableSure()->insert(Inst);
}

#endif
