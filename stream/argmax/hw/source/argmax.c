#include "hw_defines.h"

void argmax() {
  volatile dType_32t *STR_IN = (dType_32t *)(StreamIn);
  volatile dType_32t *STR_OUT = (dType_32t *)(StreamOut);
  volatile dType_32t max = 0;
  volatile dType_32t index = 0;

  for (dType_Reg i = 0; i < INPUT_SIZE; i++) {
	// Required since once FIFO is accessed the element is popped out.
	int tmp = *STR_IN;
    if (tmp > max) {
      index = i;
      max = tmp;    
   } 
  }
  *STR_OUT = index;
}