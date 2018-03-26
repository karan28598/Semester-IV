library ieee;
use ieee.std_logic_1164.all;


entity jkflip is 
	port ( input :in std_logic_vector (1 downto 0);
		  clr,clk,pre : in std_logic;
		   q,qbar : out std_logic
		   );
end jkflip;

architecture  archjk of jkflip is
signal qs,qb: std_logic;
begin

process (clr,pre,clk) is
begin
if (clr = '0') then
qs <= '0';
qb <= not qs;
elsif (pre = '0') then
qs <= '1';
qb <= not qs;
elsif (clk'event and clk = '1' )then
case input is 
when "00" => qs <= qs; 
			qb <= not qs;
when "01" => qs <= '0'; qb <= not qs;
when "10" => qs <= '1'; qb <= not qs;
when "11" => qs <= not qs;qb <= not qs;
when others => qs<='Z';
end case;
end if;
q<=qs;
qbar<=qb;
end process;
end archjk;


