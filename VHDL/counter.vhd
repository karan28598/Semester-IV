Library ieee;
Use ieee .std_logic_1164.all;
Use ieee.std_logic_unsigned.all;
Use ieee.std_logic_arith.all;
entity counter is
port (clk,rst:instd_logic;
	q:out std_logic_vector(3 downto 0));
	end entity;
architecture behave of counter is 
signalq_s:std_logic_vector(3 downto 0):="0100";
begin
	process (clk ,rst,q_s)
		begin
			if (rst='0') then 
				q_s<="0100";
			elsif(clk'event and clk='0')then
			if (q_s< "1111") then
				q_s<=q_s+1;
			end if;
			end if;
			q<=q_s;
	end process;
end behave;
