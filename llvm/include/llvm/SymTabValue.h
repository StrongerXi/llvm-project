//===-- llvm/SymTabDef.h - Implement SymbolTable Defs ------------*- C++ -*--=//
//
// This subclass of Def implements a def that has a symbol table for keeping
// track of children.  This is used by the DefHolder template class...
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_SYMTABDEF_H
#define LLVM_SYMTABDEF_H

#include "llvm/Value.h"

class SymbolTable;
class ConstantPool;

// `ValueWithSymTab` is a more accurate name
class SymTabValue : public Value {
private:
  SymbolTable *SymTab;
  ConstantPool *ConstPool;

protected:
  void setParentSymTab(SymbolTable *ST);

public:
  SymTabValue(const Type *Ty, ValueTy dty, const std::string &name = "");
  ~SymTabValue();

  inline SymbolTable *getSymbolTable() { return SymTab; }
  inline const SymbolTable *getSymbolTable() const { return SymTab; }
  inline ConstantPool &getConstantPool() { return *ConstPool; }
  inline const ConstantPool &getConstantPool() const { return *ConstPool; }
};

#endif
