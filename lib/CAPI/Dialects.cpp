//===- Dialects.cpp - CAPI for dialects -----------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "cvm-c/Dialects.h"

#include "cvm/Dialect/Cvm/IR/Cvm.h"
#include "mlir-c/IR.h"
#include "mlir/include/mlir/CAPI/IR.h"
#include "mlir/CAPI/Registration.h"
#include "mlir/IR/Types.h"
#include "llvm/ADT/StringRef.h"

//===----------------------------------------------------------------------===//
// Cvm dialect and types
//===----------------------------------------------------------------------===//

using namespace mlir;
using namespace mlir::cvm;

MLIR_DEFINE_CAPI_DIALECT_REGISTRATION(Cvm, cvm, CvmDialect)

bool mlirTypeIsACvmStreamType(MlirType type) {
  return unwrap(type).isa<StreamType>();
}

MlirType mlirCvmStreamTypeGet(MlirContext context, MlirType elementType) {
  return wrap(StreamType::get(unwrap(context), unwrap(elementType)));
}
