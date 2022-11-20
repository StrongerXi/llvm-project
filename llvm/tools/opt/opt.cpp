//===------------------------------------------------------------------------===
// LLVM 'OPT' UTILITY
//
// This utility may be invoked in the following manner:
//  opt --help               - Output information about command line switches
//  opt [options] -dce       - Run a dead code elimination pass on input
//                             bytecodes
//  opt [options] -constprop - Run a constant propogation pass on input
//                             bytecodes
//  opt [options] -inline    - Run a method inlining pass on input bytecodes
//  opt [options] -strip     - Strip symbol tables out of methods
//  opt [options] -mstrip    - Strip module & method symbol tables
//
// Optimizations may be specified an arbitrary number of times on the command
// line, they are run in the order specified.
//
// TODO: Add a -all option to keep applying all optimizations until the program
//       stops permuting.
// TODO: Add a -h command line arg that prints all available optimizations
// TODO: Add a -q command line arg that quiets "XXX pass made modifications"
//
//===------------------------------------------------------------------------===

#include "llvm/Assembly/Writer.h"
#include "llvm/Bytecode/Reader.h"
#include "llvm/Bytecode/Writer.h"
#include "llvm/Module.h"
#include "llvm/Opt/AllOpts.h"
#include "llvm/Tools/CommandLine.h"
#include <fstream>
#include <iostream>

struct {
  const std::string ArgName, Name;
  bool (*OptPtr)(Module *C);
} OptTable[] = {
    {"-dce", "Dead Code Elimination", DoDeadCodeElimination},
    {"-constprop", "Constant Propogation", DoConstantPropogation},
    {"-inline", "Method Inlining", DoMethodInlining},
    {"-strip", "Strip Symbols", DoSymbolStripping},
    {"-mstrip", "Strip Module Symbols", DoFullSymbolStripping},
};

int main(int argc, char **argv) {
  ToolCommandLine Opts(argc, argv, false);
  bool Quiet = false;

  for (int i = 1; i < argc; i++) {
    if (std::string(argv[i]) == std::string("--help")) {
      std::cerr << argv[0] << " usage:\n"
                << "  " << argv[0]
                << " --help  - Print this usage information\n";
      return 1;
    } else if (std::string(argv[i]) == std::string("-q")) {
      Quiet = true;
      argv[i] = 0;
    }
  }

  std::ostream *Out = &std::cout; // Default to printing to stdout...

  Module *C = ParseBytecodeFile(Opts.getInputFilename());
  if (C == 0) {
    std::cerr << "bytecode didn't read correctly.\n";
    return 1;
  }

  for (int i = 1; i < argc; i++) {
    if (argv[i] == 0)
      continue;
    unsigned j;
    for (j = 0; j < sizeof(OptTable) / sizeof(OptTable[0]); j++) {
      if (std::string(argv[i]) == OptTable[j].ArgName) {
        if (OptTable[j].OptPtr(C) && !Quiet)
          std::cerr << OptTable[j].Name << " pass made modifications!\n";
        break;
      }
    }

    if (j == sizeof(OptTable) / sizeof(OptTable[0]))
      std::cerr << "'" << argv[i] << "' argument unrecognized: ignored\n";
  }

  if (Opts.getOutputFilename() != "-") {
    Out = new std::ofstream(Opts.getOutputFilename().c_str(),
                            (Opts.getForce() ? 0 : 0) | std::ios::out);
    if (!Out->good()) {
      std::cerr << "Error opening " << Opts.getOutputFilename() << "!\n";
      delete C;
      return 1;
    }
  }

  // Okay, we're done now... write out result...
  WriteBytecodeToFile(C, *Out);
  delete C;

  if (Out != &std::cout)
    delete Out;
  return 0;
}
