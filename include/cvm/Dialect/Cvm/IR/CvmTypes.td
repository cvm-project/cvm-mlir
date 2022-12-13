//===-- CvmTypes.td - Cvm dialect types --------*- tablegen -*-===//
//
// Licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef CVM_DIALECT_CVM_IR_CVMTYPES
#define CVM_DIALECT_CVM_IR_CVMTYPES

include "cvm/Dialect/Cvm/IR/CvmDialect.td"
include "cvm/Dialect/Cvm/IR/CvmInterfaces.td"
include "mlir/Dialect/LLVMIR/LLVMOpBase.td"
include "mlir/IR/AttrTypeBase.td"
include "mlir/IR/BuiltinAttributes.td"
include "mlir/IR/OpBase.td"

// Base class for Cvm dialect types.
// class Cvm_Type<string name, string typeMnemonic, list<Trait> traits = []>
//     : TypeDef<Cvm_Dialect, name, traits> {
//   let mnemonic = typeMnemonic;
// }

#endif // CVM_DIALECT_CVM_IR_CVMTYPES
