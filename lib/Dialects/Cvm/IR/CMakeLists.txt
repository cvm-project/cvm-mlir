add_mlir_library(MLIRCvm
  Cvm.cpp
  LINK_LIBS PUBLIC
  MLIRIR
  DEPENDS
  MLIRCvmInterfacesIncGen
  MLIRCvmOpsIncGen
)
