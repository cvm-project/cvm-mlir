//===- Dialects.h - CAPI for dialects -----------------------------*- C -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef CVM_C_DIALECTS_H
#define CVM_C_DIALECTS_H

#include "mlir-c/IR.h"
#include "mlir-c/Registration.h"
#include "mlir-c/Support.h"

#ifdef __cplusplus
extern "C" {
#endif

//===----------------------------------------------------------------------===//
// CVM dialect
//===----------------------------------------------------------------------===//

MLIR_DECLARE_CAPI_DIALECT_REGISTRATION(Cvm, cvm);

MLIR_CAPI_EXPORTED
bool mlirTypeIsACvmStreamType(MlirType type);

MLIR_CAPI_EXPORTED
MlirType mlirCvmStreamTypeGet(MlirContext context, MlirType elementType);


#ifdef __cplusplus
}
#endif

#endif // CVM_C_DIALECTS_H
