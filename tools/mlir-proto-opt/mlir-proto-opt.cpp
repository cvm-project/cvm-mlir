//===- mlir-opt.cpp - MLIR Optimizer Driver -------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// Main entry function for mlir-opt for when built as standalone binary.
// Reuse Registration.cpp as much as possible.
//
//===----------------------------------------------------------------------===//

#include "mlir/IR/Dialect.h"
#include "mlir/InitAllDialects.h"
#include "mlir/InitAllPasses.h"
#include "mlir/Tools/mlir-opt/MlirOptMain.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/InitLLVM.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/ToolOutputFile.h"

using namespace mlir;

#include "cvm/Dialect/Cvm/IR/Cvm.h"

static void registerCvmDialects(DialectRegistry &registry) {
  registry.insert<
      // clang-format off
      mlir::cvm::CvmDialect
      // clang-format on
      >();
}
  
int main(int argc, char **argv) {
  llvm::InitLLVM y(argc, argv);

  DialectRegistry registry;
  registerAllDialects(registry);
  registerCvmDialects(registry);

  return failed(MlirOptMain(argc, argv, "MLIR modular optimizer driver\n",
                              registry,
                            /*preloadDialectsInContext=*/true));
}