#include "hw_defines.h"

void relu() {
  volatile dType_32t *STR_IN = (dType_32t *)(StreamIn);
  volatile dType_32t *STR_OUT = (dType_32t *)(StreamOut);

  #pragma clang unroll_count(1)
  for (dType_Reg i = 0; i < INPUT_SIZE; i++) {
	// Required since once FIFO is accessed the element is popped out.
	int tmp = *STR_IN;
    if (tmp > 0) {
      *STR_OUT = tmp;
    } else {
      *STR_OUT = 0;
    }
  }

// INVALID CODE. Multiple accesses to FIFO port causes deadlock.
//  if (*STR_IN > 0) {
//    *STR_OUT = *STR_IN;
//  } else {
//    *STR_OUT = *STR_IN;
// }
}