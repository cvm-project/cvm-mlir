add_mlir_library(CvmUtils
  MLIRSupport.cpp
  NameAssigner.cpp

  LINK_LIBS PUBLIC
  MLIRIR
  MLIRLLVMDialect
  MLIRSCFDialect
)
