--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____
--  /   /\/   /
-- /___/  \  /    Vendor: Xilinx
-- \   \   \/     Version: P.20131013
--  \   \         Application: netgen
--  /   /         Filename: Lab2updown_translate.vhd
-- /___/   /\     Timestamp: Wed Jul  9 21:16:51 2014
-- \   \  /  \ 
--  \___\/\___\
--             
-- Command	: -intstyle ise -rpw 100 -tpw 0 -ar Structure -tm Lab2updown -w -dir netgen/translate -ofmt vhdl -sim Lab2updown.ngd Lab2updown_translate.vhd 
-- Device	: 6slx4csg225-2
-- Input file	: Lab2updown.ngd
-- Output file	: /home/jebediah/My_Stuff/Programs/assignments/ENGS31/StateMachine/netgen/translate/Lab2updown_translate.vhd
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
library SIMPRIM;
use SIMPRIM.VCOMPONENTS.ALL;
use SIMPRIM.VPACKAGE.ALL;

entity Lab2updown is
  port (
    Clk : in STD_LOGIC := 'X'; 
    UP_L : in STD_LOGIC := 'X'; 
    Q : out STD_LOGIC_VECTOR ( 1 downto 0 ) 
  );
end Lab2updown;

architecture Structure of Lab2updown is
  signal Clk_BUFGP : STD_LOGIC; 
  signal UP_L_IBUF_4 : STD_LOGIC; 
  signal Clk_BUFGP_IBUFG_2 : STD_LOGIC; 
  signal VCC : STD_LOGIC; 
  signal GND : STD_LOGIC; 
  signal iQ : STD_LOGIC_VECTOR ( 1 downto 0 ); 
  signal Result : STD_LOGIC_VECTOR ( 1 downto 0 ); 
begin
  iQ_0 : X_FF
    generic map(
      INIT => '0'
    )
    port map (
      CLK => Clk_BUFGP,
      I => Result(0),
      O => iQ(0),
      CE => VCC,
      SET => GND,
      RST => GND
    );
  iQ_1 : X_FF
    generic map(
      INIT => '0'
    )
    port map (
      CLK => Clk_BUFGP,
      I => Result(1),
      O => iQ(1),
      CE => VCC,
      SET => GND,
      RST => GND
    );
  Result_1_1 : X_LUT3
    generic map(
      INIT => X"96"
    )
    port map (
      ADR0 => UP_L_IBUF_4,
      ADR1 => iQ(1),
      ADR2 => iQ(0),
      O => Result(1)
    );
  UP_L_IBUF : X_BUF
    port map (
      I => UP_L,
      O => UP_L_IBUF_4
    );
  Result_0_1_INV_0 : X_INV
    port map (
      I => iQ(0),
      O => Result(0)
    );
  Clk_BUFGP_BUFG : X_CKBUF
    port map (
      I => Clk_BUFGP_IBUFG_2,
      O => Clk_BUFGP
    );
  Clk_BUFGP_IBUFG : X_CKBUF
    port map (
      I => Clk,
      O => Clk_BUFGP_IBUFG_2
    );
  Q_1_OBUF : X_OBUF
    port map (
      I => iQ(1),
      O => Q(1)
    );
  Q_0_OBUF : X_OBUF
    port map (
      I => iQ(0),
      O => Q(0)
    );
  NlwBlock_Lab2updown_VCC : X_ONE
    port map (
      O => VCC
    );
  NlwBlock_Lab2updown_GND : X_ZERO
    port map (
      O => GND
    );
  NlwBlockROC : X_ROC
    generic map (ROC_WIDTH => 100 ns)
    port map (O => GSR);
  NlwBlockTOC : X_TOC
    port map (O => GTS);

end Structure;

