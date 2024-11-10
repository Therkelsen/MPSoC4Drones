// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2020.2 (lin64) Build 3064766 Wed Nov 18 09:12:47 MST 2020
// Date        : Fri Nov  8 16:12:57 2024
// Host        : hephaestus running 64-bit Ubuntu 20.04.6 LTS
// Command     : write_verilog -force -mode synth_stub
//               /home/therk/MPSoC4Drones/hdl/projects/u96v2_sbc_mp4d_2020_2/u96v2_sbc_mp4d.gen/sources_1/bd/u96v2_sbc_mp4d/ip/u96v2_sbc_mp4d_array_inverter_0_0/u96v2_sbc_mp4d_array_inverter_0_0_stub.v
// Design      : u96v2_sbc_mp4d_array_inverter_0_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xczu3eg-sbva484-1-i
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* x_core_info = "array_inverter,Vivado 2020.2" *)
module u96v2_sbc_mp4d_array_inverter_0_0(s_axi_AXI_CPU_AWADDR, 
  s_axi_AXI_CPU_AWVALID, s_axi_AXI_CPU_AWREADY, s_axi_AXI_CPU_WDATA, s_axi_AXI_CPU_WSTRB, 
  s_axi_AXI_CPU_WVALID, s_axi_AXI_CPU_WREADY, s_axi_AXI_CPU_BRESP, s_axi_AXI_CPU_BVALID, 
  s_axi_AXI_CPU_BREADY, s_axi_AXI_CPU_ARADDR, s_axi_AXI_CPU_ARVALID, 
  s_axi_AXI_CPU_ARREADY, s_axi_AXI_CPU_RDATA, s_axi_AXI_CPU_RRESP, s_axi_AXI_CPU_RVALID, 
  s_axi_AXI_CPU_RREADY, ap_clk, ap_rst_n, interrupt)
/* synthesis syn_black_box black_box_pad_pin="s_axi_AXI_CPU_AWADDR[10:0],s_axi_AXI_CPU_AWVALID,s_axi_AXI_CPU_AWREADY,s_axi_AXI_CPU_WDATA[31:0],s_axi_AXI_CPU_WSTRB[3:0],s_axi_AXI_CPU_WVALID,s_axi_AXI_CPU_WREADY,s_axi_AXI_CPU_BRESP[1:0],s_axi_AXI_CPU_BVALID,s_axi_AXI_CPU_BREADY,s_axi_AXI_CPU_ARADDR[10:0],s_axi_AXI_CPU_ARVALID,s_axi_AXI_CPU_ARREADY,s_axi_AXI_CPU_RDATA[31:0],s_axi_AXI_CPU_RRESP[1:0],s_axi_AXI_CPU_RVALID,s_axi_AXI_CPU_RREADY,ap_clk,ap_rst_n,interrupt" */;
  input [10:0]s_axi_AXI_CPU_AWADDR;
  input s_axi_AXI_CPU_AWVALID;
  output s_axi_AXI_CPU_AWREADY;
  input [31:0]s_axi_AXI_CPU_WDATA;
  input [3:0]s_axi_AXI_CPU_WSTRB;
  input s_axi_AXI_CPU_WVALID;
  output s_axi_AXI_CPU_WREADY;
  output [1:0]s_axi_AXI_CPU_BRESP;
  output s_axi_AXI_CPU_BVALID;
  input s_axi_AXI_CPU_BREADY;
  input [10:0]s_axi_AXI_CPU_ARADDR;
  input s_axi_AXI_CPU_ARVALID;
  output s_axi_AXI_CPU_ARREADY;
  output [31:0]s_axi_AXI_CPU_RDATA;
  output [1:0]s_axi_AXI_CPU_RRESP;
  output s_axi_AXI_CPU_RVALID;
  input s_axi_AXI_CPU_RREADY;
  input ap_clk;
  input ap_rst_n;
  output interrupt;
endmodule
