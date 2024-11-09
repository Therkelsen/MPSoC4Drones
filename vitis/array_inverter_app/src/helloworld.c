#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xarray_inverter.h"
#include "xparameters.h"
#include "sleep.h"

#define DATA_SIZE 100
#define DATA_SIZE_BYTES (DATA_SIZE * sizeof(int))  // Number of bytes needed for DATA_SIZE elements

XArray_inverter array_inverter;
XArray_inverter_Config *configPtr;

int main()
{
    init_platform();

    // Initialize configuration pointer for the array_inverter IP
    configPtr = XArray_inverter_LookupConfig(XPAR_ARRAY_INVERTER_0_DEVICE_ID);
    int x_status = XArray_inverter_CfgInitialize(&array_inverter, configPtr);
    if (x_status != XST_SUCCESS) {
        print("IP initialization failed\n\r");
        return XST_FAILURE;
    }

    // Define input data arrays
    int in1[DATA_SIZE] = {0};
    int out[DATA_SIZE] = {0}; // Initialize output array

    xil_printf("\n\rIn array:\n\r");
    for(int i = 0; i < DATA_SIZE; i++){
    	in1[i] = i+1;
    	xil_printf("in[%d] = %d\n\r", i, in1[i]);
    	usleep(25000);
    }


    xil_printf("\n\rOut array:\n\r");
    for(int i = 0; i < DATA_SIZE; i++){
    	out[i] = 0;
    	xil_printf("out[%d] = %d\n\r", i, out[i]);
    	usleep(25000);
    }

    // Write data to 'in1' using the provided Byte Write functions
    XArray_inverter_Write_in1_Bytes(&array_inverter, 0, (char*)in1, DATA_SIZE_BYTES);

    // Start the IP core
    XArray_inverter_Start(&array_inverter);

    xil_printf("Starting Array Inverter application\n\r");

    while(!XArray_inverter_IsDone(&array_inverter)){
    	usleep(100);
    }

    // Read back data from 'in1' using Byte Read function
    XArray_inverter_Read_out_r_Bytes(&array_inverter, 0, (char*)out, DATA_SIZE_BYTES);

    xil_printf("Base address of in1: 0x%x\n\r", XArray_inverter_Get_in1_BaseAddress(&array_inverter));
    xil_printf("Base address of in1: 0x%x\n\r", XArray_inverter_Get_out_r_BaseAddress(&array_inverter));

    xil_printf("\n\rInverted out array:\n\r");
    for (int i = 0; i < DATA_SIZE; i++) {
        xil_printf("out[%d] = %d\n\r", i, out[i]);
        usleep(25000);
    }

    xil_printf("Successfully inverted array\n\r");

    xil_printf("Successfully ran Array Inverter application\n\r");
    while(1){
    	sleep(1);
    }

    cleanup_platform();
    return 0;
}
