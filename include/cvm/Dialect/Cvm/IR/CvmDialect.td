//===-- CvmDialect.td - Cvm dialect ------------*- tablegen -*-===//
//
// Licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef CVM_DIALECT_CVM_IR_CVMDIALECT
#define CVM_DIALECT_CVM_IR_CVMDIALECT

include "mlir/IR/OpBase.td"


//===----------------------------------------------------------------------===//
// Dialect definition
//===----------------------------------------------------------------------===//

def Cvm_Dialect : Dialect {
  let name = "cvm";
  let cppNamespace = "::mlir::cvm";
  let summary = "Dialect mirroring the CVM IR.";
  let description = [{
    Dialect that has an 1-1 correspondence with CVM to allow for easier implementation of optimization passes in the MLIR ecosystem.
  }];
  let useDefaultTypePrinterParser = 1;
}

#endif // CVM_DIALECT_CVM_IR_CVMDIALECT
