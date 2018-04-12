library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
entity shift_register is
	port (	clk,reset,lin,rin : in std_logic;
			sel : in std_logic_vector (1 downto 0);
			output : out std_logic_vector (3 downto 0));
end entity;
architecture arch of shift_register  is
signal qs : std_logic_vector (3 downto 0) := "0000"; 
begin
process (clk,sel) 
begin
if (clk'event and clk = '1') then
if (reset = '1') then 
qs <= "0000";
else 
case sel is
when "00" => qs <= qs;
when "01" => qs <= qs(2 downto 0) & lin;
when "10" => qs <= rin & qs(3 downto 1);
when "11" => qs <= qs(2 downto 0) & qs(3);
when others => null;
end case;
end if;
end if;
end process;
output <= qs;
end arch;
