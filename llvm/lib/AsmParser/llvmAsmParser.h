/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
#define YYTOKENTYPE
/* Put the tokens into the symbol table, so that GDB and other debuggers
   know about them.  */
enum yytokentype {
  ESINT64VAL = 258,
  EUINT64VAL = 259,
  SINTVAL = 260,
  UINTVAL = 261,
  VOID = 262,
  BOOL = 263,
  SBYTE = 264,
  UBYTE = 265,
  SHORT = 266,
  USHORT = 267,
  INT = 268,
  UINT = 269,
  LONG = 270,
  ULONG = 271,
  FLOAT = 272,
  DOUBLE = 273,
  STRING = 274,
  TYPE = 275,
  LABEL = 276,
  VAR_ID = 277,
  LABELSTR = 278,
  STRINGCONSTANT = 279,
  IMPLEMENTATION = 280,
  TRUE = 281,
  FALSE = 282,
  BEGINTOK = 283,
  END = 284,
  DECLARE = 285,
  PHI = 286,
  CALL = 287,
  RET = 288,
  BR = 289,
  SWITCH = 290,
  NEG = 291,
  NOT = 292,
  TOINT = 293,
  TOUINT = 294,
  ADD = 295,
  SUB = 296,
  MUL = 297,
  DIV = 298,
  REM = 299,
  SETLE = 300,
  SETGE = 301,
  SETLT = 302,
  SETGT = 303,
  SETEQ = 304,
  SETNE = 305,
  MALLOC = 306,
  ALLOCA = 307,
  FREE = 308,
  LOAD = 309,
  STORE = 310,
  GETFIELD = 311,
  PUTFIELD = 312
};
#endif
/* Tokens.  */
#define ESINT64VAL 258
#define EUINT64VAL 259
#define SINTVAL 260
#define UINTVAL 261
#define VOID 262
#define BOOL 263
#define SBYTE 264
#define UBYTE 265
#define SHORT 266
#define USHORT 267
#define INT 268
#define UINT 269
#define LONG 270
#define ULONG 271
#define FLOAT 272
#define DOUBLE 273
#define STRING 274
#define TYPE 275
#define LABEL 276
#define VAR_ID 277
#define LABELSTR 278
#define STRINGCONSTANT 279
#define IMPLEMENTATION 280
#define TRUE 281
#define FALSE 282
#define BEGINTOK 283
#define END 284
#define DECLARE 285
#define PHI 286
#define CALL 287
#define RET 288
#define BR 289
#define SWITCH 290
#define NEG 291
#define NOT 292
#define TOINT 293
#define TOUINT 294
#define ADD 295
#define SUB 296
#define MUL 297
#define DIV 298
#define REM 299
#define SETLE 300
#define SETGE 301
#define SETLT 302
#define SETGT 303
#define SETEQ 304
#define SETNE 305
#define MALLOC 306
#define ALLOCA 307
#define FREE 308
#define LOAD 309
#define STORE 310
#define GETFIELD 311
#define PUTFIELD 312

#if !defined YYSTYPE && !defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 338 "llvmAsmParser.y"
{
  Module *ModuleVal;
  Method *MethodVal;
  MethodArgument *MethArgVal;
  BasicBlock *BasicBlockVal;
  TerminatorInst *TermInstVal;
  Instruction *InstVal;
  ConstPoolVal *ConstVal;
  const Type *TypeVal;

  std::list<MethodArgument *> *MethodArgList;
  std::list<Value *> *ValueList;
  std::list<const Type *> *TypeList;
  std::list<std::pair<ConstPoolVal *, BasicBlock *>> *JumpTable;
  std::vector<ConstPoolVal *> *ConstVector;

  int64_t SInt64Val;
  uint64_t UInt64Val;
  int SIntVal;
  unsigned UIntVal;

  char *StrVal;   // This memory is allocated by strdup!
  ValID ValIDVal; // May contain memory allocated by strdup

  Instruction::UnaryOps UnaryOpVal;
  Instruction::BinaryOps BinaryOpVal;
  Instruction::TermOps TermOpVal;
  Instruction::MemoryOps MemOpVal;
}
/* Line 1529 of yacc.c.  */
#line 193 "llvmAsmParser.tab.h"
YYSTYPE;
#define yystype YYSTYPE /* obsolescent; will be withdrawn */
#define YYSTYPE_IS_DECLARED 1
#define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE llvmAsmlval;
