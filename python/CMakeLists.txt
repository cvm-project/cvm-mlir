include(AddMLIRPython)

# Specifies that all MLIR packages are co-located under the `mlir_cvm`
# top level package (the API has been embedded in a relocatable way).
add_compile_definitions("MLIR_PYTHON_PACKAGE_PREFIX=mlir_cvm.")

# ###############################################################################
# Sources
# ###############################################################################
declare_mlir_python_sources(CvmPythonSources)
declare_mlir_python_sources(CvmPythonSources.Dialects
  ADD_TO_PARENT CvmPythonSources)

declare_mlir_dialect_python_bindings(
  ADD_TO_PARENT CvmPythonSources.Dialects
  ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/mlir_cvm"
  TD_FILE dialects/CvmOps.td
  SOURCES
  dialects/cvm.py
  DIALECT_NAME cvm
)

declare_mlir_python_extension(CvmPythonSources.DialectExtension
  MODULE_NAME _cvmDialects
  ADD_TO_PARENT CvmPythonSources
  SOURCES
  CvmDialects.cpp
  EMBED_CAPI_LINK_LIBS
  CvmCAPI
)

declare_mlir_python_sources(CvmPythonSources.ExecutionEngine
  ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/mlir_cvm"
  ADD_TO_PARENT CvmPythonSources
  SOURCES_GLOB
    runtime/*.py
)

# ###############################################################################
# Common CAPI
# ###############################################################################
add_mlir_python_common_capi_library(CvmPythonCAPI
  INSTALL_COMPONENT CvmPythonModules
  INSTALL_DESTINATION python_packages/cvm/mlir_cvm/_mlir_libs
  OUTPUT_DIRECTORY "${IREE_LLVM_SANDBOX_BINARY_DIR}/python_packages/mlir_cvm/_mlir_libs"
  RELATIVE_INSTALL_ROOT "../../../.."
  DECLARED_SOURCES
  CvmPythonSources
  MLIRPythonExtension.AllPassesRegistration
  MLIRPythonSources.Core
  MLIRPythonSources.ExecutionEngine
  MLIRPythonSources.Passes
)

# ###############################################################################
# Instantiation of all Python modules
# ###############################################################################
add_mlir_python_modules(CvmPythonModules
  ROOT_PREFIX "${IREE_LLVM_SANDBOX_BINARY_DIR}/python_packages/mlir_cvm"
  INSTALL_PREFIX "python_packages/mlir_cvm"
  DECLARED_SOURCES
  CvmPythonSources
  MLIRPythonExtension.AllPassesRegistration
  MLIRPythonSources.Core
  MLIRPythonSources.ExecutionEngine
  MLIRPythonSources.Passes
  COMMON_CAPI_LINK_LIBS
  CvmPythonCAPI
)
