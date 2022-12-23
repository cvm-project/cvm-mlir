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
include "mlir/IR/AttrTypeBase.td"
include "mlir/IR/BuiltinAttributes.td"
include "mlir/IR/OpBase.td"

// Base class for Cvm dialect types.
class Cvm_Type<string name, string typeMnemonic, list<Trait> traits = []>
    : TypeDef<Cvm_Dialect, name, traits> {
  let mnemonic = typeMnemonic;
}

// List of LLVM-compatible atomic types
def Cvm_AtomicTypes {
  list<Type> types = [I1, I8, I16, I32, I64,
                      F16, F32, F64];
}

// Any LLVM-compatible atomic type
def Cvm_AnyAtomicType
  : AnyTypeOf<Cvm_AtomicTypes.types>;

// Tuple of atomics
def Cvm_TupleOfAtomics: TupleOf<[Cvm_AnyAtomicType]>;

// Array
def Cvm_Array: 1DTensorOf<[Cvm_TupleOfAtomics]>;

// Tuple 
def Cvm_Tuple: TupleOf<!listconcat([Cvm_Array], Cvm_AtomicTypes.types)>;


// Collections
def Cvm_Collection : Cvm_Type<"Collection", "collection"> {
  let summary = "Collection of tuples of elements of the given type";
  let parameters = (ins "Type": $elementType);
  let assemblyFormat = "`<` qualified($elementType) `>`";
  let description = [{
    A collection of elements of a particular type that is ordered and
    can only be iterated over in that order one element at the time.
    Collection is the main data type that cvm ops consume and produce.
  }];
}

class Cvm_CollectionOf<Type elementType>
  : Type<And<[Cvm_Collection.predicate,
              SubstLeaves<"$_self",
                          "$_self.cast<CollectionType>().getElementType()",
                          elementType.predicate>]>,
             "collection with elements of type " # elementType.summary>;

/// An CVM collection consisting of tuples.
def Cvm_CollectionOfTuples
  : Cvm_CollectionOf<Cvm_Tuple>;

// def Cvm_Tensor : Cvm_Type<"Tensor", "tensor"> {
//   let summary = "2D array of elements of the given type";
//   let parameters = (ins "Type":$firstElementType, "Type":$secondElementType);
//   let assemblyFormat = 
//     "`<` qualified($firstElementType) `,` qualified($secondElementType) `>`";
//   let description = [{
//     A 2d array of elements of a particular type that is ordered and (2)
//     can only be iterated over in that order one array at the time.
//     Tensor is a secondary data type that a few cvm ops consume and produce.
//   }];
// }

#endif // CVM_DIALECT_CVM_IR_CVMTYPES
