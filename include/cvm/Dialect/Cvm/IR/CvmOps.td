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

class Cvm_Op<string mnemonic, list<Trait> traits = []> :
    Op<Cvm_Dialect, mnemonic, traits> {
}

def Cvm_ParameterLookupOp : Cvm_Op<"param_lookup",
    [TypesMatchWith<
        "the signature of the predicate must match the element type",
        "output",
        "input",
        "$_self.cast<CollectionType>().getElementType()">]>{
  let summary = "Parameter lookup operator";
  let description = [{ 
    Operator that returns the provided collection so that
    other operations do not have to be aware of input types
  }];

  // The parameter lookup operation takes a primary type input.
  let arguments = (ins AnyTuple:$input);

  // The parameter lookup operation returns a collection
  let results = (outs Cvm_CollectionOfTuples:$output);

  let assemblyFormat = [{
    `(` $input `)` attr-dict `:` type($output)
  }];
}
// def Cvm_MapOp : Cvm_Op<"map"> {
//   let summary = "map operator";
//   let description = [{ 
//     to be completed later
//   }];

//   // The parameter lookup operation takes a primary type input.
//   let arguments = (ins Cvm_Collection:$input);

//   // The parameter lookup operation returns a collection
//   let results = (outs Cvm_Collection:$output);

//   let assemblyFormat = [{
//     `(` $input `:` type($input) `)` `:` type($output)
//   }];
// }
#endif // CVM_DIALECT_CVM_IR_CVMOPS
