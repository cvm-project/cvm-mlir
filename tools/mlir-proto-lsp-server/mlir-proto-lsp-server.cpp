//===-- mlir-proto-lsp-server.cpp - LSP server for sandbox ------*- C++ -*-===//
//
// Licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file implements a sandbox-specific MLIR LSP Language server. This
/// extends the as-you-type diagnostics in VS Code to dialects defined in the
/// sandbox. Implementation essentially as explained here:
/// https://mlir.llvm.org/docs/Tools/MLIRLSP/.
///
//===----------------------------------------------------------------------===//

#include "mlir/IR/DialectRegistry.h"
#include "mlir/InitAllDialects.h"
#include "mlir/InitAllPasses.h"
#include "mlir/Support/LogicalResult.h"
#include "mlir/Tools/mlir-lsp-server/MlirLspServerMain.h"

using namespace mlir;

#ifdef SANDBOX_ENABLE_CVM
#include "iterators/Conversion/Passes.h"
#include "iterators/Dialect/Cvm/IR/Cvm.h"

static void registerCvmDialects(DialectRegistry &registry) {
  registry.insert<
      // clang-format off
      mlir::iterators::CvmDialect,
      // clang-format on
      >();
  registerCvmConversionPasses();
}
#else
static void registerCvmDialects(DialectRegistry &registry) {}
#endif

int main(int argc, char **argv) {
  registerAllPasses();

  DialectRegistry registry;
  registerAllDialects(registry);
  registerCvmDialects(registry);

  return mlir::failed(mlir::MlirLspServerMain(argc, argv, registry));
}
