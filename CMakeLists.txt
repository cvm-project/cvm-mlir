if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  message(FATAL_ERROR
    "This project is intended to be built as part of LLVM via "
    "-DLLVM_EXTERNAL_PROJECTS=iree_llvm_sandbox "
    "-DLLVM_EXTERNAL_IREE_LLVM_SANDBOX_SOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR}")
endif()

set(IREE_LLVM_SANDBOX_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}")
message(STATUS "iree_llvm_sandbox build directory: ${IREE_LLVM_SANDBOX_BINARY_DIR}")

# # ###############################################################################
# Set some variables
# ###############################################################################
set(MLIR_MAIN_SRC_DIR ${LLVM_MAIN_SRC_DIR}/../mlir)
set(MLIR_INCLUDE_DIR ${LLVM_MAIN_SRC_DIR}/../mlir/include)
set(MLIR_TABLEGEN_OUTPUT_DIR ${CMAKE_BINARY_DIR}/tools/mlir/include)

list(APPEND CMAKE_MODULE_PATH ${MLIR_MAIN_SRC_DIR}/cmake/modules)
list(APPEND CMAKE_MODULE_PATH ${LLVM_MAIN_SRC_DIR}/cmake)
set(MLIR_TABLEGEN_EXE mlir-tblgen)

# ###############################################################################
# Set include paths
# ###############################################################################
include_directories(SYSTEM ${MLIR_INCLUDE_DIR})
include_directories(SYSTEM ${MLIR_TABLEGEN_OUTPUT_DIR})

include_directories(${LLVM_INCLUDE_DIRS})
include_directories(${MLIR_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_BINARY_DIR}/include)

include_directories(include)
include_directories(${IREE_LLVM_SANDBOX_BINARY_DIR}/include)

# ###############################################################################
# Enable python (assumes enabled MLIR bindings via MLIR_ENABLE_BINDINGS_PYTHON)
# ###############################################################################
if(NOT DEFINED MLIR_ENABLE_BINDINGS_PYTHON)
  message(FATAL_ERROR
    "This project requires MLIR_ENABLE_BINDINGS_PYTHON=ON")
endif()

include(MLIRDetectPythonEnv)
mlir_configure_python_dev_packages()

# ###############################################################################
# Enable LLVM stuff
# ###############################################################################
include(TableGen)
include(AddLLVM)
include(AddMLIR)

# ###############################################################################
# Subdirs to recurse into
# ###############################################################################
add_subdirectory(lib)
add_subdirectory(include)
add_subdirectory(python)
add_subdirectory(tools)