add_mlir_public_c_api_library(CvmCAPI
    Dialects.cpp
  LINK_LIBS PUBLIC
    MLIRCvm
)
