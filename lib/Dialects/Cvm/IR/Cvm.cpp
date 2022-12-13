//===-- Cvm.cpp - Cvm dialect -----------------------*- C++ -*-===//
//
// Licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "cvm/Dialect/Cvm/IR/Cvm.h"
#include "mlir/Dialect/LLVMIR/LLVMTypes.h"
#include "mlir/IR/DialectImplementation.h"
#include "mlir/Support/LogicalResult.h"
#include "llvm/ADT/TypeSwitch.h"

using namespace mlir;
using namespace mlir::cvm;

//===----------------------------------------------------------------------===//
// Cvm dialect
//===----------------------------------------------------------------------===//

#include "cvm/Dialect/Cvm/IR/CvmOpsDialect.cpp.inc"

void CvmDialect::initialize() {
#define GET_OP_LIST
  addOperations<
#include "cvm/Dialect/Cvm/IR/CvmOps.cpp.inc"
      >();
//  addTypes<
// #define GET_TYPEDEF_LIST
// #include "cvm/Dialect/Cvm/IR/CvmOpsTypes.cpp.inc"
//       >();
}

//===----------------------------------------------------------------------===//
// Cvm interfaces
//===----------------------------------------------------------------------===//

#include "cvm/Dialect/Cvm/IR/CvmOpInterfaces.cpp.inc"
#include "cvm/Dialect/Cvm/IR/CvmTypeInterfaces.cpp.inc"

//===----------------------------------------------------------------------===//
// Cvm operations
//===----------------------------------------------------------------------===//

#define GET_OP_CLASSES
#include "cvm/Dialect/Cvm/IR/CvmOps.cpp.inc"

//===----------------------------------------------------------------------===//
// Cvm types
//===----------------------------------------------------------------------===//

#define GET_TYPEDEF_CLASSES
#include "cvm/Dialect/Cvm/IR/CvmOpsTypes.cpp.inc"
