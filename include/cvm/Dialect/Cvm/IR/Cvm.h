//===-- CvmDialect.h - Cvm dialect ------------------*- C++ -*-===//
//
// Licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef CVM_DIALECT_CVM_IR_CVM_H
#define CVM_DIALECT_CVM_IR_CVM_H

#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/IR/Dialect.h"
#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/OpImplementation.h"
#include "mlir/IR/SymbolTable.h"
#include "mlir/Interfaces/InferTypeOpInterface.h"

#include "cvm/Dialect/Cvm/IR/CvmOpsDialect.h.inc"

namespace mlir {
namespace cvm {
#include "cvm/Dialect/Cvm/IR/CvmOpInterfaces.h.inc"
#include "cvm/Dialect/Cvm/IR/CvmTypeInterfaces.h.inc"
} // namespace cvm
} // namespace mlir

#define GET_TYPEDEF_CLASSES
#include "cvm/Dialect/Cvm/IR/CvmOpsTypes.h.inc"

#define GET_OP_CLASSES
#include "cvm/Dialect/Cvm/IR/CvmOps.h.inc"

#endif // CVM_DIALECT_CVM_IR_CVM_H
