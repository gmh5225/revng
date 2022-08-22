#pragma once

//
// This file is distributed under the MIT License. See LICENSE.md for details.
//

#include <array>
#include <string>

#include "llvm/ADT/ArrayRef.h"
#include "llvm/Support/raw_ostream.h"

#include "revng/Pipeline/Contract.h"
#include "revng/Pipes/FunctionStringMap.h"

namespace revng::pipes {

class YieldControlFlow {
public:
  static constexpr const auto Name = "YieldCFG";

public:
  inline std::array<pipeline::ContractGroup, 1> getContract() const {
    return { pipeline::ContractGroup(kinds::FunctionAssemblyInternal,
                                     pipeline::Exactness::Exact,
                                     0,
                                     kinds::FunctionControlFlowGraphSVG,
                                     1,
                                     pipeline::InputPreservation::Preserve) };
  }

public:
  void run(pipeline::Context &Context,
           const FunctionStringMap &Input,
           FunctionStringMap &Output);

  void print(const pipeline::Context &Ctx,
             llvm::raw_ostream &OS,
             llvm::ArrayRef<std::string> ContainerNames) const;
};

} // namespace revng::pipes
