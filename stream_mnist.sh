#!/bin/bash
#FLAGS="HWACC,LLVMRuntime,LLVMInterface,DeviceMMR,LLVMOp,LLVMParse"
FLAGS="HWACC,DeviceMMR"
BENCH=""
DEBUG="false"
PRINT_TO_FILE="false"
TYPE="cache"

# Input file paths relative to the base repo.
INPUT="inputs/mnist/bin/inputs/mnist_input0.bin"
M0="inputs/mnist/bin/m0.bin"
M1="inputs/mnist/bin/m1.bin"


while getopts "b:f:dp" opt
	do
		case $opt in
			d )
				DEBUG="true"
				;;
			b )
				BENCH=${OPTARG}
				;;
			p )
				PRINT_TO_FILE="true"
				;;
			f )
				FLAGS+=",${OPTARG}"
				;;
			* )
				echo "Invalid argument: ${OPTARG}"
				exit 1
				;;
		esac
done

if [ "${BENCH}" == "" ]; then
	echo "No benchmark specified."
	echo "Usage: $0 -b BENCHMARK (-f DEBUGFLAG) (-p) (-d)"
	exit 2
fi

if [ "${DEBUG}" == "true" ]; then
	BINARY="ddd --gdb --args ${M5_PATH}/build/ARM/gem5.debug"
else
	BINARY="${M5_PATH}/build/ARM/gem5.opt"
fi

KERNEL=$LAB_PATH/stream/${BENCH}/host/main.elf
SYS_OPTS="--mem-size=4GB \
          --kernel=$KERNEL \
          --disk-image=$M5_PATH/baremetal/common/fake.iso \
          --machine-type=VExpress_GEM5_V1 \
          --dtb-file=none --bare-metal \
          --cpu-type=DerivO3CPU"
CACHE_OPTS="--caches --l2cache --acc_cache"

OUTDIR=BM_STREAM/${BENCH}

RUN_SCRIPT="$BINARY --debug-flags=$FLAGS --outdir=$OUTDIR \
			gem5-config/run_mnist_stream.py $SYS_OPTS \
			--accpath=$LAB_PATH/stream \
			--accbench=$BENCH $CACHE_OPTS \
			--input $INPUT --m0 $M0 --m1 $M1"

if [ "${PRINT_TO_FILE}" == "true" ]; then
	mkdir -p $OUTDIR
	$RUN_SCRIPT > ${OUTDIR}/debug-trace.txt
else
	$RUN_SCRIPT
fi

# Debug Flags List
#
# IOAcc
# ClassDetail
# CommInterface
# ComputeUnit
# LLVMInterface
# ComputeNode
# LLVMRegister
# LLVMOp
# LLVMParse
# LLVMGEP
# LLVMRuntime == ComputeNode + LLVMRegister + LLVMOp + LLVMParse
# NoncoherentDma - bfs, fft, gemm, md-knn, nw, spmv


