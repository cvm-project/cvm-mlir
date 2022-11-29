add_mlir_dialect(CvmOps cvm)
add_dependencies(MLIRCvm MLIRCvmOpsIncGen)

set(LLVM_TARGET_DEFINITIONS CvmInterfaces.td)
mlir_tablegen(CvmOpInterfaces.h.inc -gen-op-interface-decls)
mlir_tablegen(CvmOpInterfaces.cpp.inc -gen-op-interface-defs)
mlir_tablegen(CvmTypeInterfaces.h.inc -gen-type-interface-decls)
mlir_tablegen(CvmTypeInterfaces.cpp.inc -gen-type-interface-defs)
add_public_tablegen_target(MLIRCvmInterfacesIncGen)
add_dependencies(MLIRCvm MLIRCvmInterfacesIncGen)

add_dependencies(mlir-headers
  MLIRCvmInterfacesIncGen
  MLIRCvmOpsIncGen
)
