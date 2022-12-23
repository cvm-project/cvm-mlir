func.func @first_step(%arg: tuple<i32>) {
  %0 = cvm.param_lookup (%arg) : !cvm.collection<tuple<i32>>
  return
}