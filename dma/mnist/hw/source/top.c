#include "../hw_defines.h"

void top(uint64_t input, uint64_t m0_addr, uint64_t m1_addr, uint64_t n, uint64_t m, uint64_t p, uint64_t result) {
  // Define Device MMRs

  // Stage 1:  Set up args for
  // Inputs: idden_layer = gemm(m0, input) m0[128:784] *
  // mnist_input[784:1], Output = [128:1]

  // Invoke and wait for accelerator

  // Stage 2:  Set up args for Relu
  // Inputs: Relu(hidden_layer) Inputs [128,1] = Output [128,1]
  // Invoke and wait for accelerator

  // Stage 3:  Set up args for gemm(m1, hidden_layer)
  // Input: [10:128] * [128:1] Output : [10:1].
  // Have a loop here to perform the operation in rounds. 
  // Each round limited to the size of the DMA. 

  // Stage 4:  Set up args for argmax
  // Input: [10:1] Output : [1:1] (scalar).
  // Invoke and wait for accelerator
}