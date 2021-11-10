#include "../../common/dma.h"
#include "../../common/m5ops.h"
#include "../defines.h"
#include "host.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

volatile uint8_t *top = (uint8_t *)0x2f000000;
volatile uint32_t *arg1 = (uint32_t *)0x2f000001;
volatile uint32_t *arg2 = (uint32_t *)0x2f000009;
volatile uint32_t *arg3 = (uint32_t *)0x2f000011;
volatile uint32_t *arg4 = (uint32_t *)0x2f000019;
volatile uint32_t *arg5 = (uint32_t *)0x2f000021;
volatile uint32_t *arg6 = (uint32_t *)0x2f000029;
volatile uint32_t *arg7 = (uint32_t *)0x2f000031;
volatile uint32_t *arg8 = (uint32_t *)0x2f000039;

void runHead(uint64_t m1, uint64_t m2);

int main(void) {
  m5_reset_stats();
  TYPE array[9] = {1, -2, 3, -4, 5, -6, 7, -8, 9};
  TYPE base = 0x80100000;

  // Move local stack to global array
  for (int i = 0; i < 9; i++) {
    *((TYPE *)base + i) = array[i];
  }
  *top = 0x0;
  TYPE *m1 = (TYPE *)base;
  TYPE *m2 = (TYPE *)(base + sizeof(TYPE) * 16);

  runHead(reinterpret_cast<intptr_t>(m1), reinterpret_cast<intptr_t>(m2));

  for (int i = 0; i < 9; i++) {
    printf("%d \n", m2[i]);
  }

  m5_dump_stats();
  m5_exit();
  return 0;
}

void runHead(uint64_t input, uint64_t output) {
  // TODO: Start top
  *arg1 = input;
  *arg2 = output;
  *top = 1;
  unsigned *common_val = (unsigned *)0x8f000000;
  while (*top != 0);
  printf("\n Finished HEAD\n");
  *top = 0;
}
