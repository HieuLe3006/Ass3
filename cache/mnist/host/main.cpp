#include "../../common/m5ops.h"
#include "../defines.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
                                      
volatile uint8_t *top =    (uint8_t *)0x2f000000;
volatile uint32_t *arg1 = (uint32_t *)0x2f000001;
volatile uint32_t *arg2 = (uint32_t *)0x2f000009;
volatile uint32_t *arg3 = (uint32_t *)0x2f000011;
volatile uint32_t *arg4 = (uint32_t *)0x2f000019;
volatile uint32_t *arg5 = (uint32_t *)0x2f000021;
volatile uint32_t *arg6 = (uint32_t *)0x2f000029;
volatile uint32_t *arg7 = (uint32_t *)0x2f000031;
volatile uint32_t *arg8 = (uint32_t *)0x2f000039;

int main(void) {
  printf("Hello World \n \0");
 

  m5_reset_stats();
  // bool fail = false;
  // Calculate offsets for each input
  TYPE input = 0x80100000;
  TYPE m0 = 0x80100000 + (784*1*sizeof(TYPE)) + 8;
  TYPE m1 = 0x80100000 + (784 * 1 * sizeof(TYPE)) + 8 + (784 * 128 * sizeof(TYPE)) + 8;

  // Create ptrs for accessing inputs
  TYPE *input_ptr = (TYPE *)input;
  TYPE *m0_ptr = (TYPE *)(m0);
  TYPE *m1_ptr = (TYPE *)(m1);

  // input[0] : rows. input[1] cols
  // Print Input.
   printf("Input Dimensions %d %d \n \0", input_ptr[0], input_ptr[1]);
  // for (int i = 0 ; i < input_ptr[0]; i++) {
  //   for (int j = 0; j < input_ptr[1]; j++) {
  //     printf("%d \n", input_ptr[i]);
  // }
  // }
   printf("M0 Dimensions %d %d \n \0", m0_ptr[0], m0_ptr[1]);

   

   printf("M1 Dimensions %d %d \n \0", m1_ptr[0], m1_ptr[1]);

   m5_dump_stats();
   m5_exit();
}
