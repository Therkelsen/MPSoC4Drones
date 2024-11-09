// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xarray_inverter.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XArray_inverter_CfgInitialize(XArray_inverter *InstancePtr, XArray_inverter_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Axi_cpu_BaseAddress = ConfigPtr->Axi_cpu_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XArray_inverter_Start(XArray_inverter *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XArray_inverter_ReadReg(InstancePtr->Axi_cpu_BaseAddress, XARRAY_INVERTER_AXI_CPU_ADDR_AP_CTRL) & 0x80;
    XArray_inverter_WriteReg(InstancePtr->Axi_cpu_BaseAddress, XARRAY_INVERTER_AXI_CPU_ADDR_AP_CTRL, Data | 0x01);
}

u32 XArray_inverter_IsDone(XArray_inverter *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XArray_inverter_ReadReg(InstancePtr->Axi_cpu_BaseAddress, XARRAY_INVERTER_AXI_CPU_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XArray_inverter_IsIdle(XArray_inverter *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XArray_inverter_ReadReg(InstancePtr->Axi_cpu_BaseAddress, XARRAY_INVERTER_AXI_CPU_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XArray_inverter_IsReady(XArray_inverter *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XArray_inverter_ReadReg(InstancePtr->Axi_cpu_BaseAddress, XARRAY_INVERTER_AXI_CPU_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XArray_inverter_EnableAutoRestart(XArray_inverter *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XArray_inverter_WriteReg(InstancePtr->Axi_cpu_BaseAddress, XARRAY_INVERTER_AXI_CPU_ADDR_AP_CTRL, 0x80);
}

void XArray_inverter_DisableAutoRestart(XArray_inverter *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XArray_inverter_WriteReg(InstancePtr->Axi_cpu_BaseAddress, XARRAY_INVERTER_AXI_CPU_ADDR_AP_CTRL, 0);
}

u32 XArray_inverter_Get_in1_BaseAddress(XArray_inverter *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Axi_cpu_BaseAddress + XARRAY_INVERTER_AXI_CPU_ADDR_IN1_BASE);
}

u32 XArray_inverter_Get_in1_HighAddress(XArray_inverter *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Axi_cpu_BaseAddress + XARRAY_INVERTER_AXI_CPU_ADDR_IN1_HIGH);
}

u32 XArray_inverter_Get_in1_TotalBytes(XArray_inverter *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XARRAY_INVERTER_AXI_CPU_ADDR_IN1_HIGH - XARRAY_INVERTER_AXI_CPU_ADDR_IN1_BASE + 1);
}

u32 XArray_inverter_Get_in1_BitWidth(XArray_inverter *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XARRAY_INVERTER_AXI_CPU_WIDTH_IN1;
}

u32 XArray_inverter_Get_in1_Depth(XArray_inverter *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XARRAY_INVERTER_AXI_CPU_DEPTH_IN1;
}

u32 XArray_inverter_Write_in1_Words(XArray_inverter *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XARRAY_INVERTER_AXI_CPU_ADDR_IN1_HIGH - XARRAY_INVERTER_AXI_CPU_ADDR_IN1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Axi_cpu_BaseAddress + XARRAY_INVERTER_AXI_CPU_ADDR_IN1_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XArray_inverter_Read_in1_Words(XArray_inverter *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XARRAY_INVERTER_AXI_CPU_ADDR_IN1_HIGH - XARRAY_INVERTER_AXI_CPU_ADDR_IN1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Axi_cpu_BaseAddress + XARRAY_INVERTER_AXI_CPU_ADDR_IN1_BASE + (offset + i)*4);
    }
    return length;
}

u32 XArray_inverter_Write_in1_Bytes(XArray_inverter *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XARRAY_INVERTER_AXI_CPU_ADDR_IN1_HIGH - XARRAY_INVERTER_AXI_CPU_ADDR_IN1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Axi_cpu_BaseAddress + XARRAY_INVERTER_AXI_CPU_ADDR_IN1_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XArray_inverter_Read_in1_Bytes(XArray_inverter *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XARRAY_INVERTER_AXI_CPU_ADDR_IN1_HIGH - XARRAY_INVERTER_AXI_CPU_ADDR_IN1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Axi_cpu_BaseAddress + XARRAY_INVERTER_AXI_CPU_ADDR_IN1_BASE + offset + i);
    }
    return length;
}

u32 XArray_inverter_Get_out_r_BaseAddress(XArray_inverter *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Axi_cpu_BaseAddress + XARRAY_INVERTER_AXI_CPU_ADDR_OUT_R_BASE);
}

u32 XArray_inverter_Get_out_r_HighAddress(XArray_inverter *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Axi_cpu_BaseAddress + XARRAY_INVERTER_AXI_CPU_ADDR_OUT_R_HIGH);
}

u32 XArray_inverter_Get_out_r_TotalBytes(XArray_inverter *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XARRAY_INVERTER_AXI_CPU_ADDR_OUT_R_HIGH - XARRAY_INVERTER_AXI_CPU_ADDR_OUT_R_BASE + 1);
}

u32 XArray_inverter_Get_out_r_BitWidth(XArray_inverter *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XARRAY_INVERTER_AXI_CPU_WIDTH_OUT_R;
}

u32 XArray_inverter_Get_out_r_Depth(XArray_inverter *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XARRAY_INVERTER_AXI_CPU_DEPTH_OUT_R;
}

u32 XArray_inverter_Write_out_r_Words(XArray_inverter *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XARRAY_INVERTER_AXI_CPU_ADDR_OUT_R_HIGH - XARRAY_INVERTER_AXI_CPU_ADDR_OUT_R_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Axi_cpu_BaseAddress + XARRAY_INVERTER_AXI_CPU_ADDR_OUT_R_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XArray_inverter_Read_out_r_Words(XArray_inverter *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XARRAY_INVERTER_AXI_CPU_ADDR_OUT_R_HIGH - XARRAY_INVERTER_AXI_CPU_ADDR_OUT_R_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Axi_cpu_BaseAddress + XARRAY_INVERTER_AXI_CPU_ADDR_OUT_R_BASE + (offset + i)*4);
    }
    return length;
}

u32 XArray_inverter_Write_out_r_Bytes(XArray_inverter *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XARRAY_INVERTER_AXI_CPU_ADDR_OUT_R_HIGH - XARRAY_INVERTER_AXI_CPU_ADDR_OUT_R_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Axi_cpu_BaseAddress + XARRAY_INVERTER_AXI_CPU_ADDR_OUT_R_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XArray_inverter_Read_out_r_Bytes(XArray_inverter *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XARRAY_INVERTER_AXI_CPU_ADDR_OUT_R_HIGH - XARRAY_INVERTER_AXI_CPU_ADDR_OUT_R_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Axi_cpu_BaseAddress + XARRAY_INVERTER_AXI_CPU_ADDR_OUT_R_BASE + offset + i);
    }
    return length;
}

void XArray_inverter_InterruptGlobalEnable(XArray_inverter *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XArray_inverter_WriteReg(InstancePtr->Axi_cpu_BaseAddress, XARRAY_INVERTER_AXI_CPU_ADDR_GIE, 1);
}

void XArray_inverter_InterruptGlobalDisable(XArray_inverter *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XArray_inverter_WriteReg(InstancePtr->Axi_cpu_BaseAddress, XARRAY_INVERTER_AXI_CPU_ADDR_GIE, 0);
}

void XArray_inverter_InterruptEnable(XArray_inverter *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XArray_inverter_ReadReg(InstancePtr->Axi_cpu_BaseAddress, XARRAY_INVERTER_AXI_CPU_ADDR_IER);
    XArray_inverter_WriteReg(InstancePtr->Axi_cpu_BaseAddress, XARRAY_INVERTER_AXI_CPU_ADDR_IER, Register | Mask);
}

void XArray_inverter_InterruptDisable(XArray_inverter *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XArray_inverter_ReadReg(InstancePtr->Axi_cpu_BaseAddress, XARRAY_INVERTER_AXI_CPU_ADDR_IER);
    XArray_inverter_WriteReg(InstancePtr->Axi_cpu_BaseAddress, XARRAY_INVERTER_AXI_CPU_ADDR_IER, Register & (~Mask));
}

void XArray_inverter_InterruptClear(XArray_inverter *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XArray_inverter_WriteReg(InstancePtr->Axi_cpu_BaseAddress, XARRAY_INVERTER_AXI_CPU_ADDR_ISR, Mask);
}

u32 XArray_inverter_InterruptGetEnabled(XArray_inverter *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XArray_inverter_ReadReg(InstancePtr->Axi_cpu_BaseAddress, XARRAY_INVERTER_AXI_CPU_ADDR_IER);
}

u32 XArray_inverter_InterruptGetStatus(XArray_inverter *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XArray_inverter_ReadReg(InstancePtr->Axi_cpu_BaseAddress, XARRAY_INVERTER_AXI_CPU_ADDR_ISR);
}

