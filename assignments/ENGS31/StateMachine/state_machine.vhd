----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    00:54:42 07/10/2014 
-- Design Name: 
-- Module Name:    state_machine - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity state_machine is
    Port ( Clk : in STD_LOGIC;
			  L : in  STD_LOGIC;
           R : in  STD_LOGIC;
           H : in  STD_LOGIC;
			  B : in STD_LOGIC;
           LIGHTS : out  STD_LOGIC_VECTOR (5 downto 0));
end state_machine;

architecture Behavioral of state_machine is
	type statetype is (idle, l1, l2, l3, r1, r2, r3, haz);
	signal state, next_state : statetype;
begin

comb_logic:
process(state, B, R, L, H)
begin
	next_state <= state;
	case state is
		when idle =>
			--lights logic
			if B = '1' then
				if R = '1' then
					LIGHTS <= "111000";
				elsif L ='1' then
					LIGHTS <= "000111";
				end if;
			else
				LIGHTS <= "000000";			
			end if;
			
			--state logic
			if H = '1' then
				next_state <= haz;
			elsif L = '1' then
				next_state <= l1;
			elsif R = '1' then
				next_state <= r1;
			--implied else next_state <= idle
			end if;
		when haz =>
			LIGHTS <= "111111";
			next_state <= idle;
			
		when l1 => 
			if B = '1' then
			LIGHTS <= "001111";
			else
			LIGHTS <= "001000";
			end if;
			
			if H = '1' then
				next_state <= haz;
			elsif L = '1' then
				next_state <= l2;
			elsif R = '1' then
				next_state <= idle;
			end if;
			
		when l2 => 
			if B = '1' then
			LIGHTS <= "011111";
			else
			LIGHTS <= "011000";
			end if;
			
			if H = '1' then
				next_state <= haz;
			elsif L = '1' then
				next_state <= l3;
			elsif R = '1' then
				next_state <= idle;
			end if;
			
		when l3 => 
			if B = '1' then
			LIGHTS <= "111111";
			else
			LIGHTS <= "111000";
			end if;
			next_state <= idle;
			
		when r1 => 
			if B = '1' then
			LIGHTS <= "111100";
			else
			LIGHTS <= "000100";
			end if;
			
			if H = '1' then
				next_state <= haz;
			elsif L = '1' then
				next_state <= idle;
			elsif R = '1' then
				next_state <= r2;
			end if;
			
		when r2 => 
			if B = '1' then
			LIGHTS <= "111110";
			else
			LIGHTS <= "000110";
			end if;
			
			if H = '1' then
				next_state <= haz;
			elsif L = '1' then
				next_state <= idle;
			elsif R = '1' then
				next_state <= r3;
			end if;
			
		when r3 =>
			if B = '1' then
			LIGHTS <= "111111";
			else
			LIGHTS <= "000111";
			end if;	
			next_state <= idle;
		when others => null;
	end case;
end process comb_logic;

StateUpdate: 
process(clk)
begin
	if rising_edge(clk) then
		state <= next_state;
	end if;
end process StateUpdate;

end Behavioral;

