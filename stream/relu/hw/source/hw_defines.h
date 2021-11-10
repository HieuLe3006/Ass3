#include "../../../common/dma.h"

/***********************************************************
 * Computation Defines
 ***********************************************************/
#define VECTOR_SIZE		9


// StreamDMA
#define INPUT_SIZE		VECTOR_SIZE
#define OUTPUT_SIZE		VECTOR_SIZE

/***********************************************************
 * Cluster Base Address
 ***********************************************************/
#define BASE			0x2F000000
/***********************************************************
 * MMR Addresses
 ***********************************************************/
#define TOP_MMR			BASE + 0x0000
#define STREAM_DMA_MMR  0x2fe00000
#define CLUSTER_DMA_MMR 0x2ff00000
#define RELU_MMR  	BASE + 0x0100

/***********************************************************
 * Memory Buffer and SPM Addresses
 ***********************************************************/
#define StreamIn  BASE + 0x1000
#define StreamOut BASE + 0x1000


