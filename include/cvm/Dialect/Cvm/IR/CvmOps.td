//===-- CvmOps.td - Cvm operations definitions -*- tablegen -*-===//
//
// Licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef CVM_DIALECT_CVM_IR_CVMOPS
#define CVM_DIALECT_CVM_IR_CVMOPS

include "cvm/Dialect/Cvm/IR/CvmDialect.td"
include "cvm/Dialect/Cvm/IR/CvmTypes.td"
include "mlir/Interfaces/InferTypeOpInterface.td"
include "mlir/IR/OpAsmInterface.td"
include "mlir/IR/OpBase.td"

class Cvm_Base_Op<string mnemonic, list<Trait> traits = []> :
    Op<Cvm_Dialect, mnemonic, traits> {
}

class Cvm_Op<string mnemonic, list<Trait> traits = []> :
    Cvm_Base_Op<mnemonic,  traits # [Cvm_CvmOpInterface]> {
}


#endif // CVM_DIALECT_CVM_IR_CVMOPS
