//===-- StringExtras.h - Useful string functions -----------------*- C++ -*--=//
//
// This file contains some functions that are useful when dealing with strings.
// No library is required when using these functinons.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_TOOLS_STRING_EXTRAS_H
#define LLVM_TOOLS_STRING_EXTRAS_H

#include "llvm/Tools/DataTypes.h"
#include <string>

static inline std::string utostr(uint64_t X, bool isNeg = false) {
  char Buffer[40];
  char *BufPtr = Buffer + 39;

  *BufPtr = 0; // Null terminate buffer...
  if (X == 0)
    *--BufPtr = '0'; // Handle special case...

  while (X) {
    *--BufPtr = '0' + (X % 10);
    X /= 10;
  }

  if (isNeg)
    *--BufPtr = '-'; // Add negative sign...

  return std::string(BufPtr);
}

static inline std::string itostr(int64_t X) {
  if (X < 0)
    return utostr((uint64_t)-X, true);
  else
    return utostr((uint64_t)X);
}

// creates ambiguity in yacc, even after changing unsigned to uint32_t, not sure
// why
// static inline std::string utostr(uint32_t X, bool isNeg = false) {
//  char Buffer[20];
//  char *BufPtr = Buffer+19;
//
//  *BufPtr = 0;                  // Null terminate buffer...
//  if (X == 0) *--BufPtr = '0';  // Handle special case...
//
//  while (X) {
//    *--BufPtr = '0' + (X % 10);
//    X /= 10;
//  }
//
//  if (isNeg) *--BufPtr = '-';   // Add negative sign...
//
//  return std::string(BufPtr);
//}

static inline std::string itostr(int X) {
  if (X < 0)
    return utostr((unsigned)-X, true);
  else
    return utostr((unsigned)X);
}

#endif
