// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XARRAY_INVERTER_H
#define XARRAY_INVERTER_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xarray_inverter_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
    u16 DeviceId;
    u32 Axi_cpu_BaseAddress;
} XArray_inverter_Config;
#endif

typedef struct {
    u64 Axi_cpu_BaseAddress;
    u32 IsReady;
} XArray_inverter;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XArray_inverter_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XArray_inverter_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XArray_inverter_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XArray_inverter_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XArray_inverter_Initialize(XArray_inverter *InstancePtr, u16 DeviceId);
XArray_inverter_Config* XArray_inverter_LookupConfig(u16 DeviceId);
int XArray_inverter_CfgInitialize(XArray_inverter *InstancePtr, XArray_inverter_Config *ConfigPtr);
#else
int XArray_inverter_Initialize(XArray_inverter *InstancePtr, const char* InstanceName);
int XArray_inverter_Release(XArray_inverter *InstancePtr);
#endif

void XArray_inverter_Start(XArray_inverter *InstancePtr);
u32 XArray_inverter_IsDone(XArray_inverter *InstancePtr);
u32 XArray_inverter_IsIdle(XArray_inverter *InstancePtr);
u32 XArray_inverter_IsReady(XArray_inverter *InstancePtr);
void XArray_inverter_EnableAutoRestart(XArray_inverter *InstancePtr);
void XArray_inverter_DisableAutoRestart(XArray_inverter *InstancePtr);

u32 XArray_inverter_Get_in1_BaseAddress(XArray_inverter *InstancePtr);
u32 XArray_inverter_Get_in1_HighAddress(XArray_inverter *InstancePtr);
u32 XArray_inverter_Get_in1_TotalBytes(XArray_inverter *InstancePtr);
u32 XArray_inverter_Get_in1_BitWidth(XArray_inverter *InstancePtr);
u32 XArray_inverter_Get_in1_Depth(XArray_inverter *InstancePtr);
u32 XArray_inverter_Write_in1_Words(XArray_inverter *InstancePtr, int offset, word_type *data, int length);
u32 XArray_inverter_Read_in1_Words(XArray_inverter *InstancePtr, int offset, word_type *data, int length);
u32 XArray_inverter_Write_in1_Bytes(XArray_inverter *InstancePtr, int offset, char *data, int length);
u32 XArray_inverter_Read_in1_Bytes(XArray_inverter *InstancePtr, int offset, char *data, int length);
u32 XArray_inverter_Get_out_r_BaseAddress(XArray_inverter *InstancePtr);
u32 XArray_inverter_Get_out_r_HighAddress(XArray_inverter *InstancePtr);
u32 XArray_inverter_Get_out_r_TotalBytes(XArray_inverter *InstancePtr);
u32 XArray_inverter_Get_out_r_BitWidth(XArray_inverter *InstancePtr);
u32 XArray_inverter_Get_out_r_Depth(XArray_inverter *InstancePtr);
u32 XArray_inverter_Write_out_r_Words(XArray_inverter *InstancePtr, int offset, word_type *data, int length);
u32 XArray_inverter_Read_out_r_Words(XArray_inverter *InstancePtr, int offset, word_type *data, int length);
u32 XArray_inverter_Write_out_r_Bytes(XArray_inverter *InstancePtr, int offset, char *data, int length);
u32 XArray_inverter_Read_out_r_Bytes(XArray_inverter *InstancePtr, int offset, char *data, int length);

void XArray_inverter_InterruptGlobalEnable(XArray_inverter *InstancePtr);
void XArray_inverter_InterruptGlobalDisable(XArray_inverter *InstancePtr);
void XArray_inverter_InterruptEnable(XArray_inverter *InstancePtr, u32 Mask);
void XArray_inverter_InterruptDisable(XArray_inverter *InstancePtr, u32 Mask);
void XArray_inverter_InterruptClear(XArray_inverter *InstancePtr, u32 Mask);
u32 XArray_inverter_InterruptGetEnabled(XArray_inverter *InstancePtr);
u32 XArray_inverter_InterruptGetStatus(XArray_inverter *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
