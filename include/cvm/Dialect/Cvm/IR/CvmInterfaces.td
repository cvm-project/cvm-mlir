//===-- CvmInterfaces.td - Cvm interfaces -------*- tablegen -*-===//
//
// Licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef CVM_DIALECT_CVM_IR_CVMINTERFACES
#define CVM_DIALECT_CVM_IR_CVMINTERFACES

include "mlir/IR/OpBase.td"

def Cvm_CvmOpInterface : OpInterface<"CvmOpInterface"> {
  let description = [{Cvm op interface.}];
}

#endif // CVM_DIALECT_CVM_IR_CVMINTERFACES
