#include "hw_defines.h"

void top(uint64_t in_addr, uint64_t out_addr) {

  // Initialize Accelerators
  volatile uint8_t *ArgmaxFlags = (uint8_t *)ARGMAX_MMR;

  // Initialize DMAs
  // StreamDma
  volatile uint8_t *StrDmaFlags = (uint8_t *)(STREAM_DMA_MMR);
  volatile uint64_t *StrDmaRdAddr = (uint64_t *)(STREAM_DMA_MMR + 4);
  volatile uint64_t *StrDmaWrAddr = (uint64_t *)(STREAM_DMA_MMR + 12);
  volatile uint32_t *StrDmaRdFrameSize = (uint32_t *)(STREAM_DMA_MMR + 20);
  volatile uint8_t *StrDmaNumRdFrames = (uint8_t *)(STREAM_DMA_MMR + 24);
  volatile uint8_t *StrDmaRdFrameBuffSize = (uint8_t *)(STREAM_DMA_MMR + 25);
  volatile uint32_t *StrDmaWrFrameSize = (uint32_t *)(STREAM_DMA_MMR + 26);
  volatile uint8_t *StrDmaNumWrFrames = (uint8_t *)(STREAM_DMA_MMR + 30);
  volatile uint8_t *StrDmaWrFrameBuffSize = (uint8_t *)(STREAM_DMA_MMR + 31);
  // MemDma
  volatile uint8_t *MemDmaFlags = (uint8_t *)(CLUSTER_DMA_MMR);
  volatile uint64_t *MemDmaRdAddr = (uint64_t *)(CLUSTER_DMA_MMR + 1);
  volatile uint64_t *MemDmaWrAddr = (uint64_t *)(CLUSTER_DMA_MMR + 9);
  volatile uint32_t *MemDmaCopyLen = (uint32_t *)(CLUSTER_DMA_MMR + 17);
  // Initialize DRAM-Stream DMA
  *StrDmaRdAddr = in_addr;
  *StrDmaRdFrameSize = 36 ; // Number of bytes being read
  *StrDmaNumRdFrames = 1;
  *StrDmaRdFrameBuffSize = 1;
  // Initialize Stream-DRAM DMA
  *StrDmaWrAddr = out_addr;
  *StrDmaWrFrameSize = 4; // Number of bytes being written. Argmax only writes out final index
  *StrDmaNumWrFrames = 1;
  *StrDmaWrFrameBuffSize = 1;
  // Fence to ensure arguments are written to
   while(*StrDmaFlags != 0x0);
  // Start Stream DMA
  *StrDmaFlags = STR_DMA_INIT_RD | STR_DMA_INIT_WR;

  *ArgmaxFlags = 0x00;
  // Start Argmax
  *ArgmaxFlags = 0x01;
  // Wait for all accelerators to finish before sending interrupt to CPU
  // Check completion if data has finished streaming.
  while ((*StrDmaFlags & 0x08) == 0x08)
    ;
    
  *ArgmaxFlags = 0x00;
  return;
}