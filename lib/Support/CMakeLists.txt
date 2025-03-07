#
# This file is distributed under the MIT License. See LICENSE.md for details.
#

revng_add_library_internal(
  revngSupport
  SHARED
  ProgramRunner.cpp
  Assert.cpp
  BasicBlockID.cpp
  CommandLine.cpp
  Debug.cpp
  IRAnnotators.cpp
  ExampleAnalysis.cpp
  FunctionTags.cpp
  IRHelpers.cpp
  LDDTree.cpp
  MetaAddress.cpp
  OriginalAssemblyAnnotationWriter.cpp
  PathList.cpp
  ProgramCounterHandler.cpp
  ResourceFinder.cpp
  SelfReferencingDbgAnnotationWriter.cpp
  Statistics.cpp)

llvm_map_components_to_libnames(LLVM_LIBRARIES Support Core Object)

target_link_libraries(revngSupport ${LLVM_LIBRARIES})

target_include_directories(revngSupport INTERFACE $<INSTALL_INTERFACE:include/>)

# revngSupport has a dependency to the generated model files because of revng.h
#
# revng.h includes model headers which depends on the generated headers. we
# cannot add the dependency to the model because the model itself depends on
# support and would generate a cyclic dependency.
#
# TODO: drop dependency from model in revng.h
add_dependencies(revngSupport generate-revngModel-tuple-tree-code)
