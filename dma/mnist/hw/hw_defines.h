//Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include "../defines.h"

#define DEV_INIT 0x01
#define DEV_INTR 0x04



// Device MMR addresses
#define TOP 0x2f000000
#define TOP_ARG1 0x2f000001
#define TOP_ARG2 0x2f000009
// Not required leaving it in here for future extensions
#define TOP_ARG3 0x2f000011
#define TOP_ARG4 0x2f000019
#define TOP_ARG5 0x2f000021
#define TOP_ARG6 0x2f000029
#define TOP_ARG7 0x2f000031
#define TOP_ARG8 0x2f000039

#define Relu       0x2f000100
#define Relu_ARG1  0x2f000101
#define Relu_ARG2  0x2f000109
// Not required leaving it in here for future extensions
#define Relu_ARG3  0x2f000111
#define Relu_ARG4  0x2f000119
#define Relu_ARG5  0x2f000121
#define Relu_ARG6  0x2f000129
#define Relu_ARG7  0x2f000131
#define Relu_ARG8  0x2f000139

#define Argmax 0x2f000200
#define Argmax_ARG1 0x2f000201
#define Argmax_ARG2 0x2f000209
// Not required leaving it in here for future extensions
#define Argmax_ARG3 0x2f000211
#define Argmax_ARG4 0x2f000219
#define Argmax_ARG5 0x2f000221
#define Argmax_ARG6 0x2f000229
#define Argmax_ARG7 0x2f000231
#define Argmax_ARG8 0x2f000239

#define Gemm 0x2f000300
#define Gemm_ARG1 0x2f000301
#define Gemm_ARG2 0x2f000309
// Not required leaving it in here for future extensions
#define Gemm_ARG3 0x2f000311
#define Gemm_ARG4 0x2f000319
#define Gemm_ARG5 0x2f000321
#define Gemm_ARG6 0x2f000329
#define Gemm_ARG7 0x2f000331
#define Gemm_ARG8 0x2f000339

// TODO: CHECK THE ADDRESSES HERE ARE WHERE YOU WANT THEM TO BE FOR PERFORMING
// THE COMPUTATION This is not useful for the cache implementations. Specify
// row/column sizes Specify the scratchpad base address
#define DMA 0x2ff00000

#define ReluSPM 0x2f100000
// #define vector_size N * sizeof(TYPE)
// // Specify offsets where relu inputs and outputs are going to be stored in the
// // scratchpad
// #define ReluM1 SPM + (vector_size * 0)
// #define ReluM2 SPM + (vector_size * 1)

#define ArgmaxSPM 0x2f200000



#define GemmSPM 0x2f300000
