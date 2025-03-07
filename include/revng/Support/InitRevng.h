#pragma once

//
// This file is distributed under the MIT License. See LICENSE.md for details.
//

#include "llvm/Support/InitLLVM.h"
#include "llvm/Support/PrettyStackTrace.h"

namespace revng {

/// Performs initialization and shutdown steps for revng tools.
///
/// By default this performs the regular LLVM initialization steps.
/// This is required in order to initialize the stack trace printers on signal.
class InitRevng : public llvm::InitLLVM {
public:
  InitRevng(int &Argc,
            const char **&Argv,
            bool InstallPipeSignalExitHandler = true) :
    InitLLVM(Argc, Argv, InstallPipeSignalExitHandler) {
    init();
  }

  InitRevng(int &Argc, char **&Argv, bool InstallPipeSignalExitHandler = true) :
    InitLLVM(Argc, Argv, InstallPipeSignalExitHandler) {
    init();
  }

private:
  void init() {
    llvm::setBugReportMsg("PLEASE submit a bug report to "
                          "https://github.com/revng/revng and include the "
                          "crash backtrace\n");
  }
};

} // namespace revng
