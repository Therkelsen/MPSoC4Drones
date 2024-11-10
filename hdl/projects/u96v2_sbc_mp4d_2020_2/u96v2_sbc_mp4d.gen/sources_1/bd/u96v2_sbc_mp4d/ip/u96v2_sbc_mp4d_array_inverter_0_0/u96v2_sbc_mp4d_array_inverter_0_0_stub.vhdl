-- Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2020.2 (lin64) Build 3064766 Wed Nov 18 09:12:47 MST 2020
-- Date        : Fri Nov  8 16:12:57 2024
-- Host        : hephaestus running 64-bit Ubuntu 20.04.6 LTS
-- Command     : write_vhdl -force -mode synth_stub
--               /home/therk/MPSoC4Drones/hdl/projects/u96v2_sbc_mp4d_2020_2/u96v2_sbc_mp4d.gen/sources_1/bd/u96v2_sbc_mp4d/ip/u96v2_sbc_mp4d_array_inverter_0_0/u96v2_sbc_mp4d_array_inverter_0_0_stub.vhdl
-- Design      : u96v2_sbc_mp4d_array_inverter_0_0
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xczu3eg-sbva484-1-i
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity u96v2_sbc_mp4d_array_inverter_0_0 is
  Port ( 
    s_axi_AXI_CPU_AWADDR : in STD_LOGIC_VECTOR ( 10 downto 0 );
    s_axi_AXI_CPU_AWVALID : in STD_LOGIC;
    s_axi_AXI_CPU_AWREADY : out STD_LOGIC;
    s_axi_AXI_CPU_WDATA : in STD_LOGIC_VECTOR ( 31 downto 0 );
    s_axi_AXI_CPU_WSTRB : in STD_LOGIC_VECTOR ( 3 downto 0 );
    s_axi_AXI_CPU_WVALID : in STD_LOGIC;
    s_axi_AXI_CPU_WREADY : out STD_LOGIC;
    s_axi_AXI_CPU_BRESP : out STD_LOGIC_VECTOR ( 1 downto 0 );
    s_axi_AXI_CPU_BVALID : out STD_LOGIC;
    s_axi_AXI_CPU_BREADY : in STD_LOGIC;
    s_axi_AXI_CPU_ARADDR : in STD_LOGIC_VECTOR ( 10 downto 0 );
    s_axi_AXI_CPU_ARVALID : in STD_LOGIC;
    s_axi_AXI_CPU_ARREADY : out STD_LOGIC;
    s_axi_AXI_CPU_RDATA : out STD_LOGIC_VECTOR ( 31 downto 0 );
    s_axi_AXI_CPU_RRESP : out STD_LOGIC_VECTOR ( 1 downto 0 );
    s_axi_AXI_CPU_RVALID : out STD_LOGIC;
    s_axi_AXI_CPU_RREADY : in STD_LOGIC;
    ap_clk : in STD_LOGIC;
    ap_rst_n : in STD_LOGIC;
    interrupt : out STD_LOGIC
  );

end u96v2_sbc_mp4d_array_inverter_0_0;

architecture stub of u96v2_sbc_mp4d_array_inverter_0_0 is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
attribute black_box_pad_pin of stub : architecture is "s_axi_AXI_CPU_AWADDR[10:0],s_axi_AXI_CPU_AWVALID,s_axi_AXI_CPU_AWREADY,s_axi_AXI_CPU_WDATA[31:0],s_axi_AXI_CPU_WSTRB[3:0],s_axi_AXI_CPU_WVALID,s_axi_AXI_CPU_WREADY,s_axi_AXI_CPU_BRESP[1:0],s_axi_AXI_CPU_BVALID,s_axi_AXI_CPU_BREADY,s_axi_AXI_CPU_ARADDR[10:0],s_axi_AXI_CPU_ARVALID,s_axi_AXI_CPU_ARREADY,s_axi_AXI_CPU_RDATA[31:0],s_axi_AXI_CPU_RRESP[1:0],s_axi_AXI_CPU_RVALID,s_axi_AXI_CPU_RREADY,ap_clk,ap_rst_n,interrupt";
attribute x_core_info : string;
attribute x_core_info of stub : architecture is "array_inverter,Vivado 2020.2";
begin
end;
