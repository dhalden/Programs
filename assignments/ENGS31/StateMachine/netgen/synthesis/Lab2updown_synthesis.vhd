--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____
--  /   /\/   /
-- /___/  \  /    Vendor: Xilinx
-- \   \   \/     Version: P.20131013
--  \   \         Application: netgen
--  /   /         Filename: Lab2updown_synthesis.vhd
-- /___/   /\     Timestamp: Thu Jul 10 01:46:25 2014
-- \   \  /  \ 
--  \___\/\___\
--             
-- Command	: -intstyle ise -ar Structure -tm Lab2updown -w -dir netgen/synthesis -ofmt vhdl -sim Lab2updown.ngc Lab2updown_synthesis.vhd 
-- Device	: xc6slx4-2-csg225
-- Input file	: Lab2updown.ngc
-- Output file	: /home/jebediah/My_Stuff/Programs/assignments/ENGS31/StateMachine/netgen/synthesis/Lab2updown_synthesis.vhd
-- # of Entities	: 1
-- Design Name	: Lab2updown
-- Xilinx	: /home/jebediah/Desktop/Derek... Seriously... This desktop.../14.7/ISE_DS/ISE/
--             
-- Purpose:    
--     This VHDL netlist is a verification model and uses simulation 
--     primitives which may not represent the true implementation of the 
--     device, however the netlist is functionally correct and should not 
--     be modified. This file cannot be synthesized and should only be used 
--     with supported simulation tools.
--             
-- Reference:  
--     Command Line Tools User Guide, Chapter 23
--     Synthesis and Simulation Design Guide, Chapter 6
--             
--------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
use UNISIM.VPKG.ALL;

entity Lab2updown is
  port (
    Clk : in STD_LOGIC := 'X'; 
    UP_L : in STD_LOGIC := 'X'; 
    Q : out STD_LOGIC_VECTOR ( 1 downto 0 ) 
  );
end Lab2updown;

architecture Structure of Lab2updown is
  signal Clk_BUFGP_0 : STD_LOGIC; 
  signal UP_L_IBUF_1 : STD_LOGIC; 
  signal iQ : STD_LOGIC_VECTOR ( 1 downto 0 ); 
  signal Result : STD_LOGIC_VECTOR ( 1 downto 0 ); 
begin
  iQ_0 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => Clk_BUFGP_0,
      D => Result(0),
      Q => iQ(0)
    );
  iQ_1 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => Clk_BUFGP_0,
      D => Result(1),
      Q => iQ(1)
    );
  Result_1_1 : LUT3
    generic map(
      INIT => X"96"
    )
    port map (
      I0 => UP_L_IBUF_1,
      I1 => iQ(1),
      I2 => iQ(0),
      O => Result(1)
    );
  UP_L_IBUF : IBUF
    port map (
      I => UP_L,
      O => UP_L_IBUF_1
    );
  Q_1_OBUF : OBUF
    port map (
      I => iQ(1),
      O => Q(1)
    );
  Q_0_OBUF : OBUF
    port map (
      I => iQ(0),
      O => Q(0)
    );
  Clk_BUFGP : BUFGP
    port map (
      I => Clk,
      O => Clk_BUFGP_0
    );
  Result_0_1_INV_0 : INV
    port map (
      I => iQ(0),
      O => Result(0)
    );

end Structure;

