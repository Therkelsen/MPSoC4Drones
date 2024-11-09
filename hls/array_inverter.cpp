#include <stdint.h>

#define DATA_SIZE 100

void array_inverter(volatile int in1[DATA_SIZE], volatile int out[DATA_SIZE]) {
	#pragma HLS INTERFACE s_axilite port=return bundle=AXI_CPU
	#pragma HLS INTERFACE s_axilite port=in1 bundle=AXI_CPU
	#pragma HLS INTERFACE s_axilite port=in2 bundle=AXI_CPU
	#pragma HLS INTERFACE s_axilite port=out bundle=AXI_CPU

	for(int i = 0; i < DATA_SIZE; i++){
		#pragma HLS PIPELINE
		#pragma HLS UNROLL factor=100
		out[i] = in1[DATA_SIZE-1-i];
	}
}
