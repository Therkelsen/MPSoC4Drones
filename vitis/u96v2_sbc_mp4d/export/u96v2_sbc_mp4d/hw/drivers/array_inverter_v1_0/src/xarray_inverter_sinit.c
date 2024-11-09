// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xarray_inverter.h"

extern XArray_inverter_Config XArray_inverter_ConfigTable[];

XArray_inverter_Config *XArray_inverter_LookupConfig(u16 DeviceId) {
	XArray_inverter_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XARRAY_INVERTER_NUM_INSTANCES; Index++) {
		if (XArray_inverter_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XArray_inverter_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XArray_inverter_Initialize(XArray_inverter *InstancePtr, u16 DeviceId) {
	XArray_inverter_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XArray_inverter_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XArray_inverter_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

