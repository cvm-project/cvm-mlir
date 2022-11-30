add_mlir_library(MLIRCvm
  Cvm.cpp

  LINK_LIBS PUBLIC
  MLIRFuncDialect
  MLIRInferTypeOpInterface
  MLIRIR
  MLIRLLVMDialect
  MLIRTabular

  DEPENDS
  MLIRCvmInterfacesIncGen
  MLIRCvmOpsIncGen
)
