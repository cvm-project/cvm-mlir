add_mlir_public_c_api_library(CvmCAPI
    Dialects.cpp
    Passes.cpp
  LINK_LIBS PUBLIC
    MLIRCvm
    MLIRPass
)
