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
  addTypes<
#define GET_TYPEDEF_LIST
#include "cvm/Dialect/Cvm/IR/CvmOpsTypes.cpp.inc"
      >();
}

//===----------------------------------------------------------------------===//
// Cvm interfaces
//===----------------------------------------------------------------------===//

#include "cvm/Dialect/Cvm/IR/CvmOpInterfaces.cpp.inc"
#include "cvm/Dialect/Cvm/IR/CvmTypeInterfaces.cpp.inc"

//===----------------------------------------------------------------------===//
// Cvm operations
//===----------------------------------------------------------------------===//

static ParseResult parseInsertValueType(AsmParser & /*parser*/, Type &valueType,
                                        Type stateType, IntegerAttr indexAttr) {
  int64_t index = indexAttr.getValue().getSExtValue();
  auto castedStateType = stateType.cast<StateType>();
  valueType = castedStateType.getFieldTypes()[index];
  return success();
}

static void printInsertValueType(AsmPrinter & /*printer*/, Operation * /*op*/,
                                 Type /*valueType*/, Type /*stateType*/,
                                 IntegerAttr /*indexAttr*/) {}

#define GET_OP_CLASSES
#include "cvm/Dialect/Cvm/IR/CvmOps.cpp.inc"

LogicalResult ExtractValueOp::inferReturnTypes(
    MLIRContext * /*context*/, Optional<Location> location, ValueRange operands,
    DictionaryAttr attributes, RegionRange regions,
    SmallVectorImpl<Type> &inferredReturnTypes) {
  auto stateType = operands[0].getType().cast<StateType>();
  auto indexAttr = attributes.getAs<IntegerAttr>("index");
  int64_t index = indexAttr.getValue().getSExtValue();
  Type fieldType = stateType.getFieldTypes()[index];
  inferredReturnTypes.assign({fieldType});
  return success();
}

//===----------------------------------------------------------------------===//
// Cvm types
//===----------------------------------------------------------------------===//

#define GET_TYPEDEF_CLASSES
#include "cvm/Dialect/Cvm/IR/CvmOpsTypes.cpp.inc"
