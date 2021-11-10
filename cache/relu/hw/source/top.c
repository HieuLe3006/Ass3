#include "../hw_defines.h"

void top(uint64_t m1_addr, uint64_t m2_addr, uint64_t SIZE) {
  // Define Device MMRs
  volatile uint8_t *ReluFlag = (uint8_t *)Relu;
  volatile uint64_t *ReluArg1 = (uint64_t *)(Relu + 1);
  volatile uint64_t *ReluArg2 = (uint64_t *)(Relu + 9);
  volatile uint64_t *ReluArg3 = (uint64_t *)(Relu + 17);

  *ReluFlag = 0x0;
  // // Set up arguments for accelerator.

  *ReluArg1 = m1_addr;
  *ReluArg2 = m2_addr;
  *ReluArg3 = SIZE;
  // // Start the accelerated function
  *ReluFlag = DEV_INIT;

  // // Poll function for finish
  while ((*ReluFlag & DEV_INTR) != DEV_INTR)
    ;
  *ReluFlag = 0x0;

  return;
}