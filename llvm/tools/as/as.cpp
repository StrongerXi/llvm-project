//===------------------------------------------------------------------------===
// LLVM 'AS' UTILITY
//
//  This utility may be invoked in the following manner:
//   as --help     - Output information about command line switches
//   as [options]      - Read LLVM assembly from stdin, write bytecode to stdout
//   as [options] x.ll - Read LLVM assembly from the x.ll file, write bytecode
//                       to the x.bc file.
//
//===------------------------------------------------------------------------===

#include "llvm/Assembly/Parser.h"
#include "llvm/Assembly/Writer.h"
#include "llvm/Bytecode/Writer.h"
#include "llvm/Module.h"
#include "llvm/Tools/CommandLine.h"
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  ToolCommandLine Opts(argc, argv);
  bool DumpAsm = false;

  for (int i = 1; i < argc; i++) {
    if (std::string(argv[i]) == std::string("-d")) {
      argv[i] = 0;
      DumpAsm = true;
    }
  }

  bool PrintMessage = false;
  for (int i = 1; i < argc; i++) {
    if (argv[i] == 0)
      continue;

    if (std::string(argv[i]) == std::string("--help")) {
      PrintMessage = true;
    } else {
      std::cerr << argv[0] << ": argument not recognized: '" << argv[i]
                << "'!\n";
    }
  }

  if (PrintMessage) {
    std::cerr << argv[0] << " usage:\n"
              << "  " << argv[0] << " --help  - Print this usage information\n"
              << "  " << argv[0] << " x.ll    - Parse <x.ll> file and output "
              << "bytecodes to x.bc\n"
              << "  " << argv[0]
              << "         - Parse stdin and write to stdout.\n";
    return 1;
  }

  std::ostream *Out = &std::cout; // Default to output to stdout...
  try {
    // Parse the file now...
    Module *C = ParseAssemblyFile(Opts);
    if (C == 0) {
      std::cerr << "assembly didn't read correctly.\n";
      return 1;
    }

    if (DumpAsm)
      std::cerr << "Here's the assembly:\n" << C;

    if (Opts.getOutputFilename() != "-") {
      Out = new std::ofstream(Opts.getOutputFilename().c_str(),
                              (Opts.getForce() ? 0 : 0) | std::ios::out);
      if (!Out->good()) {
        std::cerr << "Error opening " << Opts.getOutputFilename() << "!\n";
        delete C;
        return 1;
      }
    }

    WriteBytecodeToFile(C, *Out);

    delete C;
  } catch (const ParseException &E) {
    std::cerr << E.getMessage() << std::endl;
    return 1;
  }

  if (Out != &std::cout)
    delete Out;
  return 0;
}
