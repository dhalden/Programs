----------------------------------------------------------------------------------
-- Company: 			Engs 31 14X
-- Engineer: 			Dave Picard & Eric Hansen
-- 
-- Create Date:    	 
-- Design Name: 		
-- Module Name:    		lab3_shell 
-- Project Name: 		Lab3
-- Target Devices: 		Digilent NEXYS3 (Spartan 6)
-- Tool versions: 		ISE Design Suite 14.4
-- Description: 		Tbird tail light lab
--				
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Revised (EWH), 3 July 2014, for the Nexys3 board
-- Additional Comments: 
--
----------------------------------------------------------------------------------
-- Boilerplate: don't change this
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.numeric_std.ALL;		-- needed for arithmetic

library UNISIM;					-- needed for the BUFG component
use UNISIM.Vcomponents.ALL;


-- Entity block
-- Change the name of the entity from Lab3_shell to something more descriptive,
-- like Lab3_Tbird.

entity TBIRD is
port ( LeftTurn, RightTurn, Hazard, Brake, clk 	: in std_logic;
       LC, LB, LA, RA, RB, RC 					: out std_logic );
end TBIRD; 

architecture Behavioral of TBIRD is
-- Signals for the clock divider, which divides the 100 MHz clock down to 4 Hz
-- 100 MHz / CLOCK_DIVIDER_VALUE = 8 Hz
constant CLOCK_DIVIDER_VALUE: integer := 12500000;
signal clkdiv: integer := 0;		-- the clock divider counter
signal clk_en: std_logic := '0';	-- terminal count
signal slow_clk: std_logic;			-- the slow clock

-- Signal declarations for your state machine go here
	type statetype is (idle, l1, l2, l3, r1, r2, r3, haz);
	signal state, next_state : statetype;

begin


-- Clock buffer for 4 Hz clock
-- The BUFG component puts the slow clock onto the FPGA clocking network
Slow_clock_buffer: BUFG
      port map (I => clk_en,
                O => slow_clk );

-- Divide the 100 MHz clock down to 8 Hz, then
-- toggling the clk_en signal at 8 Hz gives a 4 Hz clock with 50% duty cycle
Clock_divider: process(clk)
begin
	if rising_edge(clk) then
	   	if clkdiv = CLOCK_DIVIDER_VALUE-1 then 
	   		clk_en <= NOT(clk_en);		
			clkdiv <= 0;
		else
			clkdiv <= clkdiv + 1;
		end if;
	end if;
end process Clock_divider;

-- Your state machine code goes here
-- Clock your state machine with the slow_clk signal
comb_logic:
process(state, Brake, RightTurn, LeftTurn, Hazard)
begin
	next_state <= state;
	case state is
		when idle =>
			--lights logic
			if Brake = '1' then
				if RightTurn = '1' then
					LIGHTS <= "111000";
				elsif LeftTurn ='1' then
					LIGHTS <= "000111";
				end if;
			else
				LIGHTS <= "000000";			
			end if;
			
			--state logic
			if Hazard= '1' then
				next_state <= haz;
			elsif LeftTurn = '1' then
				next_state <= l1;
			elsif RightTurn = '1' then
				next_state <= r1;
			--implied else next_state <= idle
			end if;
		when haz =>
			LIGHTS <= "111111";
			next_state <= idle;
			
		when l1 => 
			if Brake = '1' then
			LIGHTS <= "001111";
			else
			LIGHTS <= "001000";
			end if;
			
			if Hazard= '1' then
				next_state <= haz;
			elsif LeftTurn = '1' then
				next_state <= l2;
			elsif RightTurn = '1' then
				next_state <= idle;
			end if;
			
		when l2 => 
			if Brake = '1' then
			LIGHTS <= "011111";
			else
			LIGHTS <= "011000";
			end if;
			
			if Hazard= '1' then
				next_state <= haz;
			elsif LeftTurn= '1' then
				next_state <= l3;
			elsif RightTurn = '1' then
				next_state <= idle;
			end if;
			
		when l3 => 
			if Brake = '1' then
			LIGHTS <= "111111";
			else
			LIGHTS <= "111000";
			end if;
			next_state <= idle;
			
		when r1 => 
			if Brake = '1' then
			LIGHTS <= "111100";
			else
			LIGHTS <= "000100";
			end if;
			
			if Hazard= '1' then
				next_state <= haz;
			elsif LeftTurn= '1' then
				next_state <= idle;
			elsif RightTurn = '1' then
				next_state <= r2;
			end if;
			
		when r2 => 
			if Brake = '1' then
			LIGHTS <= "111110";
			else
			LIGHTS <= "000110";
			end if;
			
			if Hazard= '1' then
				next_state <= haz;
			elsif LeftTurn= '1' then
				next_state <= idle;
			elsif RightTurn = '1' then
				next_state <= r3;
			end if;
			
		when r3 =>
			if Brake = '1' then
			LIGHTS <= "111111";
			else
			LIGHTS <= "000111";
			end if;	
			next_state <= idle;
		when others => null;
	end case;
end process comb_logic;

StateUpdate: 
process(slow_clk)
begin
	if rising_edge(slow_clk) then
		state <= next_state;
	end if;
end process StateUpdate;


end Behavioral; 

