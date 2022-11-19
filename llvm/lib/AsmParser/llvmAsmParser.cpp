/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse llvmAsmparse
#define yylex   llvmAsmlex
#define yyerror llvmAsmerror
#define yylval  llvmAsmlval
#define yychar  llvmAsmchar
#define yydebug llvmAsmdebug
#define yynerrs llvmAsmnerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
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




/* Copy the first part of user declarations.  */
#line 13 "llvmAsmParser.y"

#include "ParserInternals.h"
#include "llvm/BasicBlock.h"
#include "llvm/Method.h"
#include "llvm/SymbolTable.h"
#include "llvm/Module.h"
#include "llvm/Type.h"
#include "llvm/DerivedTypes.h"
#include "llvm/Assembly/Parser.h"
#include "llvm/ConstantPool.h"
#include "llvm/iTerminators.h"
#include "llvm/iMemory.h"
#include <list>
#include <iostream>
#include <utility>            // Get definition of pair class
#include <stdio.h>            // This embarasment is due to our flex lexer...

int yyerror(char *ErrorMsg);  // Forward declarations to prevent "implicit 
int yylex();                  // declaration" of xxx warnings.
int yyparse();

static Module *ParserResult;
const ToolCommandLine *CurOptions = 0;

// This contains info used when building the body of a method.  It is destroyed
// when the method is completed.
//
typedef vector<Value *> ValueList;           // Numbered defs
static void ResolveDefinitions(vector<ValueList> &LateResolvers);

static struct PerModuleInfo {
  Module *CurrentModule;
  vector<ValueList> Values;     // Module level numbered definitions
  vector<ValueList> LateResolveValues;

  void ModuleDone() {
    // If we could not resolve some blocks at parsing time (forward branches)
    // resolve the branches now...
    ResolveDefinitions(LateResolveValues);

    Values.clear();         // Clear out method local definitions
    CurrentModule = 0;
  }
} CurModule;

static struct PerMethodInfo {
  Method *CurrentMethod;         // Pointer to current method being created

  vector<ValueList> Values;          // Keep track of numbered definitions
  vector<ValueList> LateResolveValues;

  inline PerMethodInfo() {
    CurrentMethod = 0;
  }

  inline ~PerMethodInfo() {}

  inline void MethodStart(Method *M) {
    CurrentMethod = M;
  }

  void MethodDone() {
    // If we could not resolve some blocks at parsing time (forward branches)
    // resolve the branches now...
    ResolveDefinitions(LateResolveValues);

    Values.clear();         // Clear out method local definitions
    CurrentMethod = 0;
  }
} CurMeth;  // Info for the current method...


//===----------------------------------------------------------------------===//
//               Code to handle definitions of all the types
//===----------------------------------------------------------------------===//

static void InsertValue(Value *D, vector<ValueList> &ValueTab = CurMeth.Values) {
  if (!D->hasName()) {             // Is this a numbered definition?
    unsigned type = D->getType()->getUniqueID();
    if (ValueTab.size() <= type)
      ValueTab.resize(type+1, ValueList());
    //printf("Values[%d][%d] = %d\n", type, ValueTab[type].size(), D);
    ValueTab[type].push_back(D);
  }
}

static Value *getVal(const Type *Type, ValID &D, 
                     bool DoNotImprovise = false) {
  switch (D.Type) {
  case 0: {                 // Is it a numbered definition?
    unsigned type = Type->getUniqueID();
    unsigned Num = (unsigned)D.Num;

    // Module constants occupy the lowest numbered slots...
    if (type < CurModule.Values.size()) {
      if (Num < CurModule.Values[type].size()) 
        return CurModule.Values[type][Num];

      Num -= CurModule.Values[type].size();
    }

    // Make sure that our type is within bounds
    if (CurMeth.Values.size() <= type)
      break;

    // Check that the number is within bounds...
    if (CurMeth.Values[type].size() <= Num)
      break;
  
    return CurMeth.Values[type][Num];
  }
  case 1: {                // Is it a named definition?
    string Name(D.Name);
    SymbolTable *SymTab = 0;
    if (CurMeth.CurrentMethod) 
      SymTab = CurMeth.CurrentMethod->getSymbolTable();
    Value *N = SymTab ? SymTab->lookup(Type, Name) : 0;

    if (N == 0) {
      SymTab = CurModule.CurrentModule->getSymbolTable();
      if (SymTab)
        N = SymTab->lookup(Type, Name);
      if (N == 0) break;
    }

    D.destroy();  // Free old strdup'd memory...
    return N;
  }

  case 2:                 // Is it a constant pool reference??
  case 3:                 // Is it an unsigned const pool reference?
  case 4:{                // Is it a string const pool reference?
    ConstPoolVal *CPV = 0;

    // Check to make sure that "Type" is an integral type, and that our 
    // value will fit into the specified type...
    switch (D.Type) {
    case 2:
      if (Type == Type::BoolTy) {  // Special handling for boolean data
        CPV = new ConstPoolBool(D.ConstPool64 != 0);
      } else {
        if (!ConstPoolSInt::isValueValidForType(Type, D.ConstPool64))
          ThrowException("Symbolic constant pool reference is invalid!");
        CPV = new ConstPoolSInt(Type, D.ConstPool64);
      }
      break;
    case 3:
      if (!ConstPoolUInt::isValueValidForType(Type, D.UConstPool64)) {
        if (!ConstPoolSInt::isValueValidForType(Type, D.ConstPool64)) {
          ThrowException("Symbolic constant pool reference is invalid!");
        } else {     // This is really a signed reference.  Transmogrify.
          CPV = new ConstPoolSInt(Type, D.ConstPool64);
        }
      } else {
        CPV = new ConstPoolUInt(Type, D.UConstPool64);
      }
      break;
    case 4:
      cerr << "FIXME: TODO: String constants [sbyte] not implemented yet!\n";
      abort();
      //CPV = new ConstPoolString(D.Name);
      D.destroy();   // Free the string memory
      break;
    }
    assert(CPV && "How did we escape creating a constant??");

    // Scan through the constant table and see if we already have loaded this
    // constant.
    //
    ConstantPool &CP = CurMeth.CurrentMethod ? 
                         CurMeth.CurrentMethod->getConstantPool() :
                           CurModule.CurrentModule->getConstantPool();
    ConstPoolVal *C = CP.find(CPV);      // Already have this constant?
    if (C) {
      delete CPV;  // Didn't need this after all, oh well.
      return C;    // Yup, we already have one, recycle it!
    }
    CP.insert(CPV);
      
    // Success, everything is kosher. Lets go!
    return CPV;
  }   // End of case 2,3,4
  }   // End of switch


  // If we reached here, we referenced either a symbol that we don't know about
  // or an id number that hasn't been read yet.  We may be referencing something
  // forward, so just create an entry to be resolved later and get to it...
  //
  if (DoNotImprovise) return 0;  // Do we just want a null to be returned?

  // TODO: Attempt to coallecse nodes that are the same with previous ones.
  Value *d = 0;
  switch (Type->getPrimitiveID()) {
  case Type::LabelTyID: d = new    BBPlaceHolder(Type, D); break;
  case Type::MethodTyID:
    d = new MethPlaceHolder(Type, D); 
    InsertValue(d, CurModule.LateResolveValues);
    return d;
//case Type::ClassTyID:      d = new ClassPlaceHolder(Type, D); break;
  default:                   d = new   DefPlaceHolder(Type, D); break;
  }

  assert(d != 0 && "How did we not make something?");
  InsertValue(d, CurMeth.LateResolveValues);
  return d;
}


//===----------------------------------------------------------------------===//
//              Code to handle forward references in instructions
//===----------------------------------------------------------------------===//
//
// This code handles the late binding needed with statements that reference
// values not defined yet... for example, a forward branch, or the PHI node for
// a loop body.
//
// This keeps a table (CurMeth.LateResolveValues) of all such forward references
// and back patchs after we are done.
//

// ResolveDefinitions - If we could not resolve some defs at parsing 
// time (forward branches, phi functions for loops, etc...) resolve the 
// defs now...
//
static void ResolveDefinitions(vector<ValueList> &LateResolvers) {
  // Loop over LateResolveDefs fixing up stuff that couldn't be resolved
  for (unsigned ty = 0; ty < LateResolvers.size(); ty++) {
    while (!LateResolvers[ty].empty()) {
      Value *V = LateResolvers[ty].back();
      LateResolvers[ty].pop_back();
      ValID &DID = getValIDFromPlaceHolder(V);

      Value *TheRealValue = getVal(Type::getUniqueIDType(ty), DID, true);

      if (TheRealValue == 0 && DID.Type == 1)
        ThrowException("Reference to an invalid definition: '" +DID.getName() +
                       "' of type '" + V->getType()->getName() + "'");
      else if (TheRealValue == 0)
        ThrowException("Reference to an invalid definition: #" +itostr(DID.Num)+
                       " of type '" + V->getType()->getName() + "'");

      V->replaceAllUsesWith(TheRealValue);
      assert(V->use_empty());
      delete V;
    }
  }

  LateResolvers.clear();
}

// addConstValToConstantPool - This code is used to insert a constant into the
// current constant pool.  This is designed to make maximal (but not more than
// possible) reuse (merging) of constants in the constant pool.  This means that
// multiple references to %4, for example will all get merged.
//
static ConstPoolVal *addConstValToConstantPool(ConstPoolVal *C) {
  vector<ValueList> &ValTab = CurMeth.CurrentMethod ? 
                                  CurMeth.Values : CurModule.Values;
  ConstantPool &CP = CurMeth.CurrentMethod ? 
                          CurMeth.CurrentMethod->getConstantPool() : 
                          CurModule.CurrentModule->getConstantPool();

  if (ConstPoolVal *CPV = CP.find(C)) {
    // Constant already in constant pool. Try to merge the two constants
    if (CPV->hasName() && !C->hasName()) {
      // Merge the two values, we inherit the existing CPV's name.  
      // InsertValue requires that the value have no name to insert correctly
      // (because we want to fill the slot this constant would have filled)
      //
      string Name = CPV->getName();
      CPV->setName("");
      InsertValue(CPV, ValTab);
      CPV->setName(Name);
      delete C;
      return CPV;
    } else if (!CPV->hasName() && C->hasName()) {
      // If we have a name on this value and there isn't one in the const 
      // pool val already, propogate it.
      //
      CPV->setName(C->getName());
      delete C;   // Sorry, you're toast
      return CPV;
    } else if (CPV->hasName() && C->hasName()) {
      // Both values have distinct names.  We cannot merge them.
      CP.insert(C);
      InsertValue(C, ValTab);
      return C;
    } else if (!CPV->hasName() && !C->hasName()) {
      // Neither value has a name, trivially merge them.
      InsertValue(CPV, ValTab);
      delete C;
      return CPV;
    }

    assert(0 && "Not reached!");
    return 0;
  } else {           // No duplication of value.
    CP.insert(C);
    InsertValue(C, ValTab);
    return C;
  } 
}

//===----------------------------------------------------------------------===//
//            RunVMAsmParser - Define an interface to this parser
//===----------------------------------------------------------------------===//
//
Module *RunVMAsmParser(const ToolCommandLine &Opts, FILE *F) {
  llvmAsmin = F;
  CurOptions = &Opts;
  llvmAsmlineno = 1;      // Reset the current line number...

  CurModule.CurrentModule = new Module();  // Allocate a new module to read
  yyparse();       // Parse the file.
  Module *Result = ParserResult;
  CurOptions = 0;
  llvmAsmin = stdin;    // F is about to go away, don't use it anymore...
  ParserResult = 0;

  return Result;
}



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 338 "llvmAsmParser.y"
{
  Module                  *ModuleVal;
  Method                  *MethodVal;
  MethodArgument          *MethArgVal;
  BasicBlock              *BasicBlockVal;
  TerminatorInst          *TermInstVal;
  Instruction             *InstVal;
  ConstPoolVal            *ConstVal;
  const Type              *TypeVal;

  list<MethodArgument*>   *MethodArgList;
  list<Value*>            *ValueList;
  list<const Type*>       *TypeList;
  list<pair<ConstPoolVal*, BasicBlock*> > *JumpTable;
  vector<ConstPoolVal*>   *ConstVector;

  int64_t                  SInt64Val;
  uint64_t                 UInt64Val;
  int                      SIntVal;
  unsigned                 UIntVal;

  char                    *StrVal;   // This memory is allocated by strdup!
  ValID                    ValIDVal; // May contain memory allocated by strdup

  Instruction::UnaryOps    UnaryOpVal;
  Instruction::BinaryOps   BinaryOpVal;
  Instruction::TermOps     TermOpVal;
  Instruction::MemoryOps   MemOpVal;
}
/* Line 193 of yacc.c.  */
#line 573 "llvmAsmParser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 586 "llvmAsmParser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   498

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  123
/* YYNRULES -- Number of states.  */
#define YYNSTATES  220

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   312

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      65,    66,    67,     2,    64,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    58,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,    60,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      61,     2,     2,    62,     2,    63,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    35,    37,
      39,    41,    43,    45,    47,    49,    51,    53,    55,    57,
      59,    61,    63,    65,    67,    69,    71,    73,    75,    77,
      79,    81,    83,    85,    87,    89,    91,    93,    96,    97,
     100,   103,   106,   109,   112,   115,   122,   128,   137,   145,
     152,   157,   161,   163,   167,   168,   170,   173,   176,   178,
     179,   182,   186,   188,   190,   191,   197,   201,   204,   206,
     208,   210,   212,   214,   216,   218,   220,   222,   227,   231,
     235,   241,   245,   248,   251,   253,   257,   260,   263,   266,
     270,   273,   274,   278,   281,   285,   295,   305,   312,   318,
     321,   324,   328,   330,   331,   337,   341,   344,   351,   353,
     356,   362,   365,   371
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      82,     0,    -1,     5,    -1,     6,    -1,     3,    -1,     4,
      -1,     8,    -1,     9,    -1,    10,    -1,    11,    -1,    12,
      -1,    13,    -1,    14,    -1,    15,    -1,    16,    -1,    17,
      -1,    18,    -1,    19,    -1,    20,    -1,    21,    -1,    71,
      -1,     7,    -1,    36,    -1,    37,    -1,    38,    -1,    39,
      -1,    40,    -1,    41,    -1,    42,    -1,    43,    -1,    44,
      -1,    45,    -1,    46,    -1,    47,    -1,    48,    -1,    49,
      -1,    50,    -1,    15,    -1,    13,    -1,    11,    -1,     9,
      -1,    16,    -1,    14,    -1,    12,    -1,    10,    -1,    75,
      -1,    76,    -1,    22,    58,    -1,    -1,    75,    70,    -1,
      76,     4,    -1,     8,    26,    -1,     8,    27,    -1,    19,
      24,    -1,    20,    71,    -1,    59,    71,    60,    59,    80,
      60,    -1,    59,    71,    60,    59,    60,    -1,    59,     4,
      61,    71,    60,    59,    80,    60,    -1,    59,     4,    61,
      71,    60,    59,    60,    -1,    62,    93,    63,    62,    80,
      63,    -1,    62,    63,    62,    63,    -1,    80,    64,    79,
      -1,    79,    -1,    81,    78,    79,    -1,    -1,    83,    -1,
      83,    90,    -1,    81,    25,    -1,    22,    -1,    -1,    71,
      84,    -1,    85,    64,    86,    -1,    85,    -1,    86,    -1,
      -1,    72,    24,    65,    87,    66,    -1,    88,    81,    28,
      -1,    94,    29,    -1,     3,    -1,     4,    -1,    26,    -1,
      27,    -1,    24,    -1,    69,    -1,    22,    -1,    91,    -1,
      92,    -1,    72,    65,    93,    66,    -1,    72,    65,    66,
      -1,    59,    71,    60,    -1,    59,     4,    61,    71,    60,
      -1,    62,    93,    63,    -1,    62,    63,    -1,    71,    67,
      -1,    71,    -1,    93,    64,    71,    -1,    94,    95,    -1,
      89,    95,    -1,    96,    97,    -1,    23,    96,    97,    -1,
      96,    99,    -1,    -1,    33,    71,    92,    -1,    33,     7,
      -1,    34,    21,    92,    -1,    34,     8,    92,    64,    21,
      92,    64,    21,    92,    -1,    35,    77,    92,    64,    21,
      92,    59,    98,    60,    -1,    98,    77,    91,    64,    21,
      92,    -1,    77,    91,    64,    21,    92,    -1,    78,   102,
      -1,    71,    92,    -1,   100,    64,    92,    -1,   100,    -1,
      -1,    74,    71,    92,    64,    92,    -1,    73,    71,    92,
      -1,    31,   100,    -1,    32,    71,    92,    65,   101,    66,
      -1,   103,    -1,    51,    71,    -1,    51,    71,    64,    14,
      92,    -1,    52,    71,    -1,    52,    71,    64,    14,    92,
      -1,    53,    71,    92,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   434,   434,   435,   442,   443,   454,   454,   454,   454,
     454,   454,   454,   455,   455,   455,   455,   455,   455,   455,
     458,   458,   463,   463,   463,   463,   464,   464,   464,   464,
     464,   465,   465,   465,   465,   465,   465,   469,   469,   469,
     469,   470,   470,   470,   470,   471,   471,   473,   476,   480,
     485,   490,   493,   496,   502,   505,   518,   522,   540,   547,
     555,   569,   572,   578,   586,   597,   602,   607,   616,   616,
     618,   626,   630,   635,   638,   642,   669,   673,   682,   685,
     688,   691,   694,   699,   702,   705,   712,   720,   725,   729,
     732,   735,   740,   743,   748,   752,   757,   761,   770,   775,
     784,   788,   792,   795,   798,   801,   806,   817,   825,   835,
     843,   847,   853,   853,   855,   860,   865,   874,   911,   915,
     920,   930,   935,   945
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ESINT64VAL", "EUINT64VAL", "SINTVAL",
  "UINTVAL", "VOID", "BOOL", "SBYTE", "UBYTE", "SHORT", "USHORT", "INT",
  "UINT", "LONG", "ULONG", "FLOAT", "DOUBLE", "STRING", "TYPE", "LABEL",
  "VAR_ID", "LABELSTR", "STRINGCONSTANT", "IMPLEMENTATION", "TRUE",
  "FALSE", "BEGINTOK", "END", "DECLARE", "PHI", "CALL", "RET", "BR",
  "SWITCH", "NEG", "NOT", "TOINT", "TOUINT", "ADD", "SUB", "MUL", "DIV",
  "REM", "SETLE", "SETGE", "SETLT", "SETGT", "SETEQ", "SETNE", "MALLOC",
  "ALLOCA", "FREE", "LOAD", "STORE", "GETFIELD", "PUTFIELD", "'='", "'['",
  "']'", "'x'", "'{'", "'}'", "','", "'('", "')'", "'*'", "$accept",
  "INTVAL", "EINT64VAL", "Types", "TypesV", "UnaryOps", "BinaryOps",
  "SIntType", "UIntType", "IntType", "OptAssign", "ConstVal",
  "ConstVector", "ConstPool", "Module", "MethodList", "OptVAR_ID",
  "ArgVal", "ArgListH", "ArgList", "MethodHeaderH", "MethodHeader",
  "Method", "ConstValueRef", "ValueRef", "TypeList", "BasicBlockList",
  "BasicBlock", "InstructionList", "BBTerminatorInst", "JumpTable", "Inst",
  "ValueRefList", "ValueRefListE", "InstVal", "MemoryInst", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,    61,    91,
      93,   120,   123,   125,    44,    40,    41,    42
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    68,    69,    69,    70,    70,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      72,    72,    73,    73,    73,    73,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    75,    75,    75,
      75,    76,    76,    76,    76,    77,    77,    78,    78,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    80,    80,    81,    81,    82,    83,    83,    84,    84,
      85,    86,    86,    87,    87,    88,    89,    90,    91,    91,
      91,    91,    91,    92,    92,    92,    71,    71,    71,    71,
      71,    71,    71,    71,    93,    93,    94,    94,    95,    95,
      96,    96,    97,    97,    97,    97,    97,    98,    98,    99,
     100,   100,   101,   101,   102,   102,   102,   102,   102,   103,
     103,   103,   103,   103
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     0,     2,
       2,     2,     2,     2,     2,     6,     5,     8,     7,     6,
       4,     3,     1,     3,     0,     1,     2,     2,     1,     0,
       2,     3,     1,     1,     0,     5,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     3,     3,
       5,     3,     2,     2,     1,     3,     2,     2,     2,     3,
       2,     0,     3,     2,     3,     9,     9,     6,     5,     2,
       2,     3,     1,     0,     5,     3,     2,     6,     1,     2,
       5,     2,     5,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      64,    48,     0,    65,     0,    67,     0,     1,    78,    79,
       2,     3,    21,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    84,    82,    80,
      81,     0,     0,    83,    20,     0,    64,   101,    66,    85,
      86,   101,    47,     0,    40,    44,    39,    43,    38,    42,
      37,    41,     0,     0,     0,     0,     0,     0,    63,    79,
      20,     0,    92,    94,     0,    93,     0,     0,    48,   101,
      97,    48,    77,    96,    51,    52,    53,    54,    79,    20,
       0,     0,     4,     5,    49,    50,     0,    89,    91,     0,
      74,    88,     0,    76,    48,     0,     0,     0,     0,    98,
     100,     0,     0,     0,     0,    20,    95,    69,    72,    73,
       0,    87,    99,   103,    20,     0,     0,    45,    46,     0,
       0,     0,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,     0,     0,     0,
       0,     0,   109,   118,    20,     0,    60,     0,    90,    68,
      70,     0,    75,   102,     0,   104,     0,    20,   116,    20,
     119,   121,    20,    20,    20,     0,    56,    62,     0,     0,
      71,     0,     0,   110,     0,     0,     0,     0,   123,   115,
       0,     0,    55,     0,    59,     0,     0,   111,   113,     0,
       0,     0,    58,     0,    61,     0,     0,   112,     0,   120,
     122,   114,    57,     0,     0,   117,     0,     0,     0,   105,
       0,   106,     0,     0,     0,     0,     0,   108,     0,   107
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    33,    84,    63,    61,   140,   141,    56,    57,   119,
       6,   167,   168,     1,     2,     3,   150,   108,   109,   110,
      36,    37,    38,    39,    40,    64,    41,    70,    71,    99,
     208,   100,   158,   198,   142,   143
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -125
static const yytype_int16 yypact[] =
{
    -125,     5,     8,   296,     4,  -125,   112,  -125,  -125,  -125,
    -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,
    -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,
    -125,   321,   210,  -125,    11,   -17,  -125,   107,  -125,  -125,
    -125,   154,  -125,    19,  -125,  -125,  -125,  -125,  -125,  -125,
    -125,  -125,   123,   296,   381,   235,   207,   172,  -125,   119,
      17,   139,  -125,   168,   200,  -125,   205,   146,   147,  -125,
    -125,    68,  -125,  -125,  -125,  -125,  -125,   168,   213,    39,
     209,   202,  -125,  -125,  -125,  -125,   296,  -125,  -125,   296,
     296,  -125,   194,  -125,    68,   406,    74,   130,   150,  -125,
    -125,   296,   216,   214,   217,    40,   168,     2,   212,  -125,
     215,  -125,  -125,   218,     7,    67,    67,  -125,  -125,    67,
     296,   296,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,
    -125,  -125,  -125,  -125,  -125,  -125,  -125,   296,   296,   296,
     296,   296,  -125,  -125,    44,     6,  -125,   112,  -125,  -125,
    -125,   296,  -125,  -125,   220,  -125,   221,     7,   222,     7,
      -4,   142,     7,     7,     7,   219,  -125,  -125,    52,   204,
    -125,   259,   261,  -125,    67,   223,   273,   275,  -125,  -125,
     226,   436,  -125,   112,  -125,    67,    67,  -125,   296,    67,
      67,    67,  -125,    55,  -125,   227,   233,   222,   229,  -125,
    -125,  -125,  -125,   272,   130,  -125,    67,    32,    28,  -125,
     232,  -125,    32,   298,   257,    67,   323,  -125,    67,  -125
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -125,  -125,  -125,    -3,   343,  -125,  -125,   -95,   -94,   -75,
     -39,    -5,  -124,   313,  -125,  -125,  -125,  -125,   199,  -125,
    -125,  -125,  -125,   -28,  -110,    30,  -125,   310,   283,   260,
    -125,  -125,   165,  -125,  -125,  -125
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -22
static const yytype_int16 yytable[] =
{
      34,    58,   117,   118,   153,   154,   155,    66,     7,   156,
       8,     9,    10,    11,    43,    44,    45,    46,    47,    48,
      49,    50,    51,   169,   149,    52,    53,     4,    60,    27,
       5,    28,    98,    29,    30,     8,     9,    44,    45,    46,
      47,    48,    49,    50,    51,    74,    75,   173,    67,   175,
      77,    79,   178,   179,   180,    98,    28,   193,    29,    30,
     176,   -20,    42,    65,   187,    54,   166,   -20,    55,    65,
       8,     9,    10,    11,    65,   195,   196,    87,    65,   199,
     200,   201,   115,   105,    65,    81,   106,   107,   211,    27,
       4,    28,   114,    29,    30,   116,   209,    92,   144,   102,
     148,    95,    96,    97,   165,   217,    65,    65,   219,   117,
     118,    65,   182,   117,   118,   202,   183,   157,   159,   183,
      43,    44,    45,    46,    47,    48,    49,    50,    51,   207,
      69,    52,    53,   212,   160,   161,   162,   163,   164,    44,
      45,    46,    47,    48,    49,    50,    51,    76,   107,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     4,
      28,    54,    29,    30,    55,    93,    85,    69,   194,   210,
      86,   120,   121,    72,   214,   157,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,    67,    31,   177,   -20,    32,    65,
      82,    83,    91,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,   -20,    28,    65,    29,    30,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    89,    28,
     111,    29,    30,    88,    89,   104,    89,   184,   183,    31,
      90,   103,    32,    62,   101,   145,   151,   146,   181,   147,
     185,   152,   186,   -21,   171,   172,   174,   189,   188,   190,
     191,   203,   204,   206,    31,   205,   213,    32,    80,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,   215,
      28,   216,    29,    30,     8,    59,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   218,    28,    35,    29,    30,    68,
     170,    73,    94,   197,   112,    31,     0,     0,    32,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      31,     0,     0,    32,     8,    78,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     0,    28,     0,    29,    30,     8,
       9,    10,    11,   113,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
      28,     0,    29,    30,     0,     0,     0,     0,     0,     0,
      31,     0,     0,    32,    43,    44,    45,    46,    47,    48,
      49,    50,    51,     0,     0,    52,    53,     0,     0,     0,
       0,     0,     0,     0,     0,    31,     0,     0,    32,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    54,   192,     0,    55
};

static const yytype_int16 yycheck[] =
{
       3,     6,    97,    97,   114,   115,   116,    24,     0,   119,
       3,     4,     5,     6,     8,     9,    10,    11,    12,    13,
      14,    15,    16,   147,    22,    19,    20,    22,    31,    22,
      25,    24,    71,    26,    27,     3,     4,     9,    10,    11,
      12,    13,    14,    15,    16,    26,    27,   157,    65,   159,
      53,    54,   162,   163,   164,    94,    24,   181,    26,    27,
      64,    65,    58,    67,   174,    59,    60,    65,    62,    67,
       3,     4,     5,     6,    67,   185,   186,    60,    67,   189,
     190,   191,     8,    86,    67,    55,    89,    90,    60,    22,
      22,    24,    95,    26,    27,    21,   206,    67,   101,    60,
      60,    33,    34,    35,    60,   215,    67,    67,   218,   204,
     204,    67,    60,   208,   208,    60,    64,   120,   121,    64,
       8,     9,    10,    11,    12,    13,    14,    15,    16,   204,
      23,    19,    20,   208,   137,   138,   139,   140,   141,     9,
      10,    11,    12,    13,    14,    15,    16,    24,   151,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    22,
      24,    59,    26,    27,    62,    28,     4,    23,   183,   207,
      61,    31,    32,    29,   212,   188,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    65,    59,    64,    65,    62,    67,
       3,     4,    66,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    65,    24,    67,    26,    27,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    64,    24,
      66,    26,    27,    63,    64,    63,    64,    63,    64,    59,
      65,    62,    62,    63,    61,    59,    64,    63,    59,    62,
      21,    66,    21,    65,    64,    64,    64,    14,    65,    14,
      64,    64,    59,    21,    59,    66,    64,    62,    63,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    21,
      24,    64,    26,    27,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    21,    24,     3,    26,    27,    36,
     151,    41,    69,   188,    94,    59,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    -1,    -1,    62,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    -1,    -1,    62,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    -1,    62
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    81,    82,    83,    22,    25,    78,     0,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    24,    26,
      27,    59,    62,    69,    71,    72,    88,    89,    90,    91,
      92,    94,    58,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    19,    20,    59,    62,    75,    76,    79,     4,
      71,    72,    63,    71,    93,    67,    24,    65,    81,    23,
      95,    96,    29,    95,    26,    27,    24,    71,     4,    71,
      63,    93,     3,     4,    70,     4,    61,    60,    63,    64,
      65,    66,    93,    28,    96,    33,    34,    35,    78,    97,
      99,    61,    60,    62,    63,    71,    71,    71,    85,    86,
      87,    66,    97,     7,    71,     8,    21,    75,    76,    77,
      31,    32,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      73,    74,   102,   103,    71,    59,    63,    62,    60,    22,
      84,    64,    66,    92,    92,    92,    92,    71,   100,    71,
      71,    71,    71,    71,    71,    60,    60,    79,    80,    80,
      86,    64,    64,    92,    64,    92,    64,    64,    92,    92,
      92,    59,    60,    64,    63,    21,    21,    92,    65,    14,
      14,    64,    60,    80,    79,    92,    92,   100,   101,    92,
      92,    92,    60,    64,    59,    66,    21,    77,    98,    92,
      91,    60,    77,    64,    91,    21,    64,    92,    21,    92
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 435 "llvmAsmParser.y"
    {
  if ((yyvsp[(1) - (1)].UIntVal) > (uint32_t)INT32_MAX)     // Outside of my range!
    ThrowException("Value too large for type!");
  (yyval.SIntVal) = (int32_t)(yyvsp[(1) - (1)].UIntVal);
;}
    break;

  case 5:
#line 443 "llvmAsmParser.y"
    {
  if ((yyvsp[(1) - (1)].UInt64Val) > (uint64_t)INT64_MAX)     // Outside of my range!
    ThrowException("Value too large for type!");
  (yyval.SInt64Val) = (int64_t)(yyvsp[(1) - (1)].UInt64Val);
;}
    break;

  case 47:
#line 473 "llvmAsmParser.y"
    {
    (yyval.StrVal) = (yyvsp[(1) - (2)].StrVal);
  ;}
    break;

  case 48:
#line 476 "llvmAsmParser.y"
    { 
    (yyval.StrVal) = 0; 
  ;}
    break;

  case 49:
#line 480 "llvmAsmParser.y"
    {     // integral constants
    if (!ConstPoolSInt::isValueValidForType((yyvsp[(1) - (2)].TypeVal), (yyvsp[(2) - (2)].SInt64Val)))
      ThrowException("Constant value doesn't fit in type!");
    (yyval.ConstVal) = new ConstPoolSInt((yyvsp[(1) - (2)].TypeVal), (yyvsp[(2) - (2)].SInt64Val));
  ;}
    break;

  case 50:
#line 485 "llvmAsmParser.y"
    {           // integral constants
    if (!ConstPoolUInt::isValueValidForType((yyvsp[(1) - (2)].TypeVal), (yyvsp[(2) - (2)].UInt64Val)))
      ThrowException("Constant value doesn't fit in type!");
    (yyval.ConstVal) = new ConstPoolUInt((yyvsp[(1) - (2)].TypeVal), (yyvsp[(2) - (2)].UInt64Val));
  ;}
    break;

  case 51:
#line 490 "llvmAsmParser.y"
    {                     // Boolean constants
    (yyval.ConstVal) = new ConstPoolBool(true);
  ;}
    break;

  case 52:
#line 493 "llvmAsmParser.y"
    {                    // Boolean constants
    (yyval.ConstVal) = new ConstPoolBool(false);
  ;}
    break;

  case 53:
#line 496 "llvmAsmParser.y"
    {         // String constants
    cerr << "FIXME: TODO: String constants [sbyte] not implemented yet!\n";
    abort();
    //$$ = new ConstPoolString($2);
    free((yyvsp[(2) - (2)].StrVal));
  ;}
    break;

  case 54:
#line 502 "llvmAsmParser.y"
    {                    // Type constants
    (yyval.ConstVal) = new ConstPoolType((yyvsp[(2) - (2)].TypeVal));
  ;}
    break;

  case 55:
#line 505 "llvmAsmParser.y"
    {      // Nonempty array constant
    // Verify all elements are correct type!
    const ArrayType *AT = ArrayType::getArrayType((yyvsp[(2) - (6)].TypeVal));
    for (unsigned i = 0; i < (yyvsp[(5) - (6)].ConstVector)->size(); i++) {
      if ((yyvsp[(2) - (6)].TypeVal) != (*(yyvsp[(5) - (6)].ConstVector))[i]->getType())
	ThrowException("Element #" + utostr(i) + " is not of type '" + 
		       (yyvsp[(2) - (6)].TypeVal)->getName() + "' as required!\nIt is of type '" +
		       (*(yyvsp[(5) - (6)].ConstVector))[i]->getType()->getName() + "'.");
    }

    (yyval.ConstVal) = new ConstPoolArray(AT, *(yyvsp[(5) - (6)].ConstVector));
    delete (yyvsp[(5) - (6)].ConstVector);
  ;}
    break;

  case 56:
#line 518 "llvmAsmParser.y"
    {                  // Empty array constant
    vector<ConstPoolVal*> Empty;
    (yyval.ConstVal) = new ConstPoolArray(ArrayType::getArrayType((yyvsp[(2) - (5)].TypeVal)), Empty);
  ;}
    break;

  case 57:
#line 522 "llvmAsmParser.y"
    {
    // Verify all elements are correct type!
    const ArrayType *AT = ArrayType::getArrayType((yyvsp[(4) - (8)].TypeVal), (int)(yyvsp[(2) - (8)].UInt64Val));
    if ((yyvsp[(2) - (8)].UInt64Val) != (yyvsp[(7) - (8)].ConstVector)->size())
      ThrowException("Type mismatch: constant sized array initialized with " +
		     utostr((yyvsp[(7) - (8)].ConstVector)->size()) +  " arguments, but has size of " + 
		     itostr((int)(yyvsp[(2) - (8)].UInt64Val)) + "!");

    for (unsigned i = 0; i < (yyvsp[(7) - (8)].ConstVector)->size(); i++) {
      if ((yyvsp[(4) - (8)].TypeVal) != (*(yyvsp[(7) - (8)].ConstVector))[i]->getType())
	ThrowException("Element #" + utostr(i) + " is not of type '" + 
		       (yyvsp[(4) - (8)].TypeVal)->getName() + "' as required!\nIt is of type '" +
		       (*(yyvsp[(7) - (8)].ConstVector))[i]->getType()->getName() + "'.");
    }

    (yyval.ConstVal) = new ConstPoolArray(AT, *(yyvsp[(7) - (8)].ConstVector));
    delete (yyvsp[(7) - (8)].ConstVector);
  ;}
    break;

  case 58:
#line 540 "llvmAsmParser.y"
    {
    if ((yyvsp[(2) - (7)].UInt64Val) != 0) 
      ThrowException("Type mismatch: constant sized array initialized with 0"
		     " arguments, but has size of " + itostr((int)(yyvsp[(2) - (7)].UInt64Val)) + "!");
    vector<ConstPoolVal*> Empty;
    (yyval.ConstVal) = new ConstPoolArray(ArrayType::getArrayType((yyvsp[(4) - (7)].TypeVal), 0), Empty);
  ;}
    break;

  case 59:
#line 547 "llvmAsmParser.y"
    {
    StructType::ElementTypes Types((yyvsp[(2) - (6)].TypeList)->begin(), (yyvsp[(2) - (6)].TypeList)->end());
    delete (yyvsp[(2) - (6)].TypeList);

    const StructType *St = StructType::getStructType(Types);
    (yyval.ConstVal) = new ConstPoolStruct(St, *(yyvsp[(5) - (6)].ConstVector));
    delete (yyvsp[(5) - (6)].ConstVector);
  ;}
    break;

  case 60:
#line 555 "llvmAsmParser.y"
    {
    const StructType *St = 
      StructType::getStructType(StructType::ElementTypes());
    vector<ConstPoolVal*> Empty;
    (yyval.ConstVal) = new ConstPoolStruct(St, Empty);
  ;}
    break;

  case 61:
#line 569 "llvmAsmParser.y"
    {
    ((yyval.ConstVector) = (yyvsp[(1) - (3)].ConstVector))->push_back(addConstValToConstantPool((yyvsp[(3) - (3)].ConstVal)));
  ;}
    break;

  case 62:
#line 572 "llvmAsmParser.y"
    {
    (yyval.ConstVector) = new vector<ConstPoolVal*>();
    (yyval.ConstVector)->push_back(addConstValToConstantPool((yyvsp[(1) - (1)].ConstVal)));
  ;}
    break;

  case 63:
#line 578 "llvmAsmParser.y"
    { 
    if ((yyvsp[(2) - (3)].StrVal)) {
      (yyvsp[(3) - (3)].ConstVal)->setName((yyvsp[(2) - (3)].StrVal));
      free((yyvsp[(2) - (3)].StrVal));
    }

    addConstValToConstantPool((yyvsp[(3) - (3)].ConstVal));
  ;}
    break;

  case 64:
#line 586 "llvmAsmParser.y"
    { 
  ;}
    break;

  case 65:
#line 597 "llvmAsmParser.y"
    {
  (yyval.ModuleVal) = ParserResult = (yyvsp[(1) - (1)].ModuleVal);
  CurModule.ModuleDone();
;}
    break;

  case 66:
#line 602 "llvmAsmParser.y"
    {
    (yyvsp[(1) - (2)].ModuleVal)->getMethodList().push_back((yyvsp[(2) - (2)].MethodVal));
    CurMeth.MethodDone();
    (yyval.ModuleVal) = (yyvsp[(1) - (2)].ModuleVal);
  ;}
    break;

  case 67:
#line 607 "llvmAsmParser.y"
    {
    (yyval.ModuleVal) = CurModule.CurrentModule;
  ;}
    break;

  case 69:
#line 616 "llvmAsmParser.y"
    { (yyval.StrVal) = 0; ;}
    break;

  case 70:
#line 618 "llvmAsmParser.y"
    {
  (yyval.MethArgVal) = new MethodArgument((yyvsp[(1) - (2)].TypeVal));
  if ((yyvsp[(2) - (2)].StrVal)) {      // Was the argument named?
    (yyval.MethArgVal)->setName((yyvsp[(2) - (2)].StrVal)); 
    free((yyvsp[(2) - (2)].StrVal));    // The string was strdup'd, so free it now.
  }
;}
    break;

  case 71:
#line 626 "llvmAsmParser.y"
    {
    (yyval.MethodArgList) = (yyvsp[(3) - (3)].MethodArgList);
    (yyvsp[(3) - (3)].MethodArgList)->push_front((yyvsp[(1) - (3)].MethArgVal));
  ;}
    break;

  case 72:
#line 630 "llvmAsmParser.y"
    {
    (yyval.MethodArgList) = new list<MethodArgument*>();
    (yyval.MethodArgList)->push_front((yyvsp[(1) - (1)].MethArgVal));
  ;}
    break;

  case 73:
#line 635 "llvmAsmParser.y"
    {
    (yyval.MethodArgList) = (yyvsp[(1) - (1)].MethodArgList);
  ;}
    break;

  case 74:
#line 638 "llvmAsmParser.y"
    {
    (yyval.MethodArgList) = 0;
  ;}
    break;

  case 75:
#line 642 "llvmAsmParser.y"
    {
  MethodType::ParamTypes ParamTypeList;
  if ((yyvsp[(4) - (5)].MethodArgList))
    for (list<MethodArgument*>::iterator I = (yyvsp[(4) - (5)].MethodArgList)->begin(); I != (yyvsp[(4) - (5)].MethodArgList)->end(); I++)
      ParamTypeList.push_back((*I)->getType());

  const MethodType *MT = MethodType::getMethodType((yyvsp[(1) - (5)].TypeVal), ParamTypeList);

  Method *M = new Method(MT, (yyvsp[(2) - (5)].StrVal));
  free((yyvsp[(2) - (5)].StrVal));  // Free strdup'd memory!

  InsertValue(M, CurModule.Values);

  CurMeth.MethodStart(M);

  // Add all of the arguments we parsed to the method...
  if ((yyvsp[(4) - (5)].MethodArgList)) {        // Is null if empty...
    Method::ArgumentListType &ArgList = M->getArgumentList();

    for (list<MethodArgument*>::iterator I = (yyvsp[(4) - (5)].MethodArgList)->begin(); I != (yyvsp[(4) - (5)].MethodArgList)->end(); I++) {
      InsertValue(*I);
      ArgList.push_back(*I);
    }
    delete (yyvsp[(4) - (5)].MethodArgList);                     // We're now done with the argument list
  }
;}
    break;

  case 76:
#line 669 "llvmAsmParser.y"
    {
  (yyval.MethodVal) = CurMeth.CurrentMethod;
;}
    break;

  case 77:
#line 673 "llvmAsmParser.y"
    {
  (yyval.MethodVal) = (yyvsp[(1) - (2)].MethodVal);
;}
    break;

  case 78:
#line 682 "llvmAsmParser.y"
    {    // A reference to a direct constant
    (yyval.ValIDVal) = ValID::create((yyvsp[(1) - (1)].SInt64Val));
  ;}
    break;

  case 79:
#line 685 "llvmAsmParser.y"
    {
    (yyval.ValIDVal) = ValID::create((yyvsp[(1) - (1)].UInt64Val));
  ;}
    break;

  case 80:
#line 688 "llvmAsmParser.y"
    {
    (yyval.ValIDVal) = ValID::create((int64_t)1);
  ;}
    break;

  case 81:
#line 691 "llvmAsmParser.y"
    {
    (yyval.ValIDVal) = ValID::create((int64_t)0);
  ;}
    break;

  case 82:
#line 694 "llvmAsmParser.y"
    {        // Quoted strings work too... especially for methods
    (yyval.ValIDVal) = ValID::create_conststr((yyvsp[(1) - (1)].StrVal));
  ;}
    break;

  case 83:
#line 699 "llvmAsmParser.y"
    {           // Is it an integer reference...?
    (yyval.ValIDVal) = ValID::create((yyvsp[(1) - (1)].SIntVal));
  ;}
    break;

  case 84:
#line 702 "llvmAsmParser.y"
    {                // It must be a named reference then...
    (yyval.ValIDVal) = ValID::create((yyvsp[(1) - (1)].StrVal));
  ;}
    break;

  case 85:
#line 705 "llvmAsmParser.y"
    {
    (yyval.ValIDVal) = (yyvsp[(1) - (1)].ValIDVal);
  ;}
    break;

  case 86:
#line 712 "llvmAsmParser.y"
    {
    Value *D = getVal(Type::TypeTy, (yyvsp[(1) - (1)].ValIDVal), true);
    if (D == 0) ThrowException("Invalid user defined type: " + (yyvsp[(1) - (1)].ValIDVal).getName());
    assert (D->getValueType() == Value::ConstantVal &&
            "Internal error!  User defined type not in const pool!");
    ConstPoolType *CPT = (ConstPoolType*)D;
    (yyval.TypeVal) = CPT->getValue();
  ;}
    break;

  case 87:
#line 720 "llvmAsmParser.y"
    {               // Method derived type?
    MethodType::ParamTypes Params((yyvsp[(3) - (4)].TypeList)->begin(), (yyvsp[(3) - (4)].TypeList)->end());
    delete (yyvsp[(3) - (4)].TypeList);
    (yyval.TypeVal) = MethodType::getMethodType((yyvsp[(1) - (4)].TypeVal), Params);
  ;}
    break;

  case 88:
#line 725 "llvmAsmParser.y"
    {               // Method derived type?
    MethodType::ParamTypes Params;     // Empty list
    (yyval.TypeVal) = MethodType::getMethodType((yyvsp[(1) - (3)].TypeVal), Params);
  ;}
    break;

  case 89:
#line 729 "llvmAsmParser.y"
    {
    (yyval.TypeVal) = ArrayType::getArrayType((yyvsp[(2) - (3)].TypeVal));
  ;}
    break;

  case 90:
#line 732 "llvmAsmParser.y"
    {
    (yyval.TypeVal) = ArrayType::getArrayType((yyvsp[(4) - (5)].TypeVal), (int)(yyvsp[(2) - (5)].UInt64Val));
  ;}
    break;

  case 91:
#line 735 "llvmAsmParser.y"
    {
    StructType::ElementTypes Elements((yyvsp[(2) - (3)].TypeList)->begin(), (yyvsp[(2) - (3)].TypeList)->end());
    delete (yyvsp[(2) - (3)].TypeList);
    (yyval.TypeVal) = StructType::getStructType(Elements);
  ;}
    break;

  case 92:
#line 740 "llvmAsmParser.y"
    {
    (yyval.TypeVal) = StructType::getStructType(StructType::ElementTypes());
  ;}
    break;

  case 93:
#line 743 "llvmAsmParser.y"
    {
    (yyval.TypeVal) = PointerType::getPointerType((yyvsp[(1) - (2)].TypeVal));
  ;}
    break;

  case 94:
#line 748 "llvmAsmParser.y"
    {
    (yyval.TypeList) = new list<const Type*>();
    (yyval.TypeList)->push_back((yyvsp[(1) - (1)].TypeVal));
  ;}
    break;

  case 95:
#line 752 "llvmAsmParser.y"
    {
    ((yyval.TypeList)=(yyvsp[(1) - (3)].TypeList))->push_back((yyvsp[(3) - (3)].TypeVal));
  ;}
    break;

  case 96:
#line 757 "llvmAsmParser.y"
    {
    (yyvsp[(1) - (2)].MethodVal)->getBasicBlocks().push_back((yyvsp[(2) - (2)].BasicBlockVal));
    (yyval.MethodVal) = (yyvsp[(1) - (2)].MethodVal);
  ;}
    break;

  case 97:
#line 761 "llvmAsmParser.y"
    { // Do not allow methods with 0 basic blocks   
    (yyval.MethodVal) = (yyvsp[(1) - (2)].MethodVal);                  // in them...
    (yyvsp[(1) - (2)].MethodVal)->getBasicBlocks().push_back((yyvsp[(2) - (2)].BasicBlockVal));
  ;}
    break;

  case 98:
#line 770 "llvmAsmParser.y"
    {
    (yyvsp[(1) - (2)].BasicBlockVal)->getInstList().push_back((yyvsp[(2) - (2)].TermInstVal));
    InsertValue((yyvsp[(1) - (2)].BasicBlockVal));
    (yyval.BasicBlockVal) = (yyvsp[(1) - (2)].BasicBlockVal);
  ;}
    break;

  case 99:
#line 775 "llvmAsmParser.y"
    {
    (yyvsp[(2) - (3)].BasicBlockVal)->getInstList().push_back((yyvsp[(3) - (3)].TermInstVal));
    (yyvsp[(2) - (3)].BasicBlockVal)->setName((yyvsp[(1) - (3)].StrVal));
    free((yyvsp[(1) - (3)].StrVal));         // Free the strdup'd memory...

    InsertValue((yyvsp[(2) - (3)].BasicBlockVal));
    (yyval.BasicBlockVal) = (yyvsp[(2) - (3)].BasicBlockVal);
  ;}
    break;

  case 100:
#line 784 "llvmAsmParser.y"
    {
    (yyvsp[(1) - (2)].BasicBlockVal)->getInstList().push_back((yyvsp[(2) - (2)].InstVal));
    (yyval.BasicBlockVal) = (yyvsp[(1) - (2)].BasicBlockVal);
  ;}
    break;

  case 101:
#line 788 "llvmAsmParser.y"
    {
    (yyval.BasicBlockVal) = new BasicBlock();
  ;}
    break;

  case 102:
#line 792 "llvmAsmParser.y"
    {              // Return with a result...
    (yyval.TermInstVal) = new ReturnInst(getVal((yyvsp[(2) - (3)].TypeVal), (yyvsp[(3) - (3)].ValIDVal)));
  ;}
    break;

  case 103:
#line 795 "llvmAsmParser.y"
    {                                       // Return with no result...
    (yyval.TermInstVal) = new ReturnInst();
  ;}
    break;

  case 104:
#line 798 "llvmAsmParser.y"
    {                         // Unconditional Branch...
    (yyval.TermInstVal) = new BranchInst((BasicBlock*)getVal(Type::LabelTy, (yyvsp[(3) - (3)].ValIDVal)));
  ;}
    break;

  case 105:
#line 801 "llvmAsmParser.y"
    {  
    (yyval.TermInstVal) = new BranchInst((BasicBlock*)getVal(Type::LabelTy, (yyvsp[(6) - (9)].ValIDVal)), 
			(BasicBlock*)getVal(Type::LabelTy, (yyvsp[(9) - (9)].ValIDVal)),
			getVal(Type::BoolTy, (yyvsp[(3) - (9)].ValIDVal)));
  ;}
    break;

  case 106:
#line 806 "llvmAsmParser.y"
    {
    SwitchInst *S = new SwitchInst(getVal((yyvsp[(2) - (9)].TypeVal), (yyvsp[(3) - (9)].ValIDVal)), 
                                   (BasicBlock*)getVal(Type::LabelTy, (yyvsp[(6) - (9)].ValIDVal)));
    (yyval.TermInstVal) = S;

    list<pair<ConstPoolVal*, BasicBlock*> >::iterator I = (yyvsp[(8) - (9)].JumpTable)->begin(), 
                                                      end = (yyvsp[(8) - (9)].JumpTable)->end();
    for (; I != end; I++)
      S->dest_push_back(I->first, I->second);
  ;}
    break;

  case 107:
#line 817 "llvmAsmParser.y"
    {
    (yyval.JumpTable) = (yyvsp[(1) - (6)].JumpTable);
    ConstPoolVal *V = (ConstPoolVal*)getVal((yyvsp[(2) - (6)].TypeVal), (yyvsp[(3) - (6)].ValIDVal), true);
    if (V == 0)
      ThrowException("May only switch on a constant pool value!");

    (yyval.JumpTable)->push_back(make_pair(V, (BasicBlock*)getVal((yyvsp[(5) - (6)].TypeVal), (yyvsp[(6) - (6)].ValIDVal))));
  ;}
    break;

  case 108:
#line 825 "llvmAsmParser.y"
    {
    (yyval.JumpTable) = new list<pair<ConstPoolVal*, BasicBlock*> >();
    ConstPoolVal *V = (ConstPoolVal*)getVal((yyvsp[(1) - (5)].TypeVal), (yyvsp[(2) - (5)].ValIDVal), true);

    if (V == 0)
      ThrowException("May only switch on a constant pool value!");

    (yyval.JumpTable)->push_back(make_pair(V, (BasicBlock*)getVal((yyvsp[(4) - (5)].TypeVal), (yyvsp[(5) - (5)].ValIDVal))));
  ;}
    break;

  case 109:
#line 835 "llvmAsmParser.y"
    {
  if ((yyvsp[(1) - (2)].StrVal))              // Is this definition named??
    (yyvsp[(2) - (2)].InstVal)->setName((yyvsp[(1) - (2)].StrVal));   // if so, assign the name...

  InsertValue((yyvsp[(2) - (2)].InstVal));
  (yyval.InstVal) = (yyvsp[(2) - (2)].InstVal);
;}
    break;

  case 110:
#line 843 "llvmAsmParser.y"
    {    // Used for PHI nodes and call statements...
    (yyval.ValueList) = new list<Value*>();
    (yyval.ValueList)->push_back(getVal((yyvsp[(1) - (2)].TypeVal), (yyvsp[(2) - (2)].ValIDVal)));
  ;}
    break;

  case 111:
#line 847 "llvmAsmParser.y"
    {
    (yyval.ValueList) = (yyvsp[(1) - (3)].ValueList);
    (yyvsp[(1) - (3)].ValueList)->push_back(getVal((yyvsp[(1) - (3)].ValueList)->front()->getType(), (yyvsp[(3) - (3)].ValIDVal)));
  ;}
    break;

  case 113:
#line 853 "llvmAsmParser.y"
    { (yyval.ValueList) = 0; ;}
    break;

  case 114:
#line 855 "llvmAsmParser.y"
    {
    (yyval.InstVal) = Instruction::getBinaryOperator((yyvsp[(1) - (5)].BinaryOpVal), getVal((yyvsp[(2) - (5)].TypeVal), (yyvsp[(3) - (5)].ValIDVal)), getVal((yyvsp[(2) - (5)].TypeVal), (yyvsp[(5) - (5)].ValIDVal)));
    if ((yyval.InstVal) == 0)
      ThrowException("binary operator returned null!");
  ;}
    break;

  case 115:
#line 860 "llvmAsmParser.y"
    {
    (yyval.InstVal) = Instruction::getUnaryOperator((yyvsp[(1) - (3)].UnaryOpVal), getVal((yyvsp[(2) - (3)].TypeVal), (yyvsp[(3) - (3)].ValIDVal)));
    if ((yyval.InstVal) == 0)
      ThrowException("unary operator returned null!");
  ;}
    break;

  case 116:
#line 865 "llvmAsmParser.y"
    {
    (yyval.InstVal) = new PHINode((yyvsp[(2) - (2)].ValueList)->front()->getType());
    while ((yyvsp[(2) - (2)].ValueList)->begin() != (yyvsp[(2) - (2)].ValueList)->end()) {
      // TODO: Ensure all types are the same... 
      ((PHINode*)(yyval.InstVal))->addIncoming((yyvsp[(2) - (2)].ValueList)->front());
      (yyvsp[(2) - (2)].ValueList)->pop_front();
    }
    delete (yyvsp[(2) - (2)].ValueList);  // Free the list...
  ;}
    break;

  case 117:
#line 874 "llvmAsmParser.y"
    {
    if (!(yyvsp[(2) - (6)].TypeVal)->isMethodType())
      ThrowException("Can only call methods: invalid type '" + 
		     (yyvsp[(2) - (6)].TypeVal)->getName() + "'!");

    const MethodType *Ty = (const MethodType*)(yyvsp[(2) - (6)].TypeVal);

    Value *V = getVal(Ty, (yyvsp[(3) - (6)].ValIDVal));
    if (V->getValueType() != Value::MethodVal || V->getType() != Ty)
      ThrowException("Cannot call: " + (yyvsp[(3) - (6)].ValIDVal).getName() + "!");

    // Create or access a new type that corresponds to the function call...
    vector<Value *> Params;

    if ((yyvsp[(5) - (6)].ValueList)) {
      // Pull out just the arguments...
      Params.insert(Params.begin(), (yyvsp[(5) - (6)].ValueList)->begin(), (yyvsp[(5) - (6)].ValueList)->end());
      delete (yyvsp[(5) - (6)].ValueList);

      // Loop through MethodType's arguments and ensure they are specified
      // correctly!
      //
      MethodType::ParamTypes::const_iterator I = Ty->getParamTypes().begin();
      unsigned i;
      for (i = 0; i < Params.size() && I != Ty->getParamTypes().end(); ++i,++I){
	if (Params[i]->getType() != *I)
	  ThrowException("Parameter " + utostr(i) + " is not of type '" + 
			 (*I)->getName() + "'!");
      }

      if (i != Params.size() || I != Ty->getParamTypes().end())
	ThrowException("Invalid number of parameters detected!");
    }

    // Create the call node...
    (yyval.InstVal) = new CallInst((Method*)V, Params);
  ;}
    break;

  case 118:
#line 911 "llvmAsmParser.y"
    {
    (yyval.InstVal) = (yyvsp[(1) - (1)].InstVal);
  ;}
    break;

  case 119:
#line 915 "llvmAsmParser.y"
    {
    ConstPoolVal *TyVal = new ConstPoolType(PointerType::getPointerType((yyvsp[(2) - (2)].TypeVal)));
    TyVal = addConstValToConstantPool(TyVal);
    (yyval.InstVal) = new MallocInst((ConstPoolType*)TyVal);
  ;}
    break;

  case 120:
#line 920 "llvmAsmParser.y"
    {
    if (!(yyvsp[(2) - (5)].TypeVal)->isArrayType() || ((const ArrayType*)(yyvsp[(2) - (5)].TypeVal))->isSized())
      ThrowException("Trying to allocate " + (yyvsp[(2) - (5)].TypeVal)->getName() + 
		     " as unsized array!");

    Value *ArrSize = getVal((yyvsp[(4) - (5)].TypeVal), (yyvsp[(5) - (5)].ValIDVal));
    ConstPoolVal *TyVal = new ConstPoolType(PointerType::getPointerType((yyvsp[(2) - (5)].TypeVal)));
    TyVal = addConstValToConstantPool(TyVal);
    (yyval.InstVal) = new MallocInst((ConstPoolType*)TyVal, ArrSize);
  ;}
    break;

  case 121:
#line 930 "llvmAsmParser.y"
    {
    ConstPoolVal *TyVal = new ConstPoolType(PointerType::getPointerType((yyvsp[(2) - (2)].TypeVal)));
    TyVal = addConstValToConstantPool(TyVal);
    (yyval.InstVal) = new AllocaInst((ConstPoolType*)TyVal);
  ;}
    break;

  case 122:
#line 935 "llvmAsmParser.y"
    {
    if (!(yyvsp[(2) - (5)].TypeVal)->isArrayType() || ((const ArrayType*)(yyvsp[(2) - (5)].TypeVal))->isSized())
      ThrowException("Trying to allocate " + (yyvsp[(2) - (5)].TypeVal)->getName() + 
		     " as unsized array!");

    Value *ArrSize = getVal((yyvsp[(4) - (5)].TypeVal), (yyvsp[(5) - (5)].ValIDVal));
    ConstPoolVal *TyVal = new ConstPoolType(PointerType::getPointerType((yyvsp[(2) - (5)].TypeVal)));
    TyVal = addConstValToConstantPool(TyVal);
    (yyval.InstVal) = new AllocaInst((ConstPoolType*)TyVal, ArrSize);
  ;}
    break;

  case 123:
#line 945 "llvmAsmParser.y"
    {
    if (!(yyvsp[(2) - (3)].TypeVal)->isPointerType())
      ThrowException("Trying to free nonpointer type " + (yyvsp[(2) - (3)].TypeVal)->getName() + "!");
    (yyval.InstVal) = new FreeInst(getVal((yyvsp[(2) - (3)].TypeVal), (yyvsp[(3) - (3)].ValIDVal)));
  ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2775 "llvmAsmParser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 951 "llvmAsmParser.y"

int yyerror(char *ErrorMsg) {
  ThrowException(string("Parse error: ") + ErrorMsg);
  return 0;
}

