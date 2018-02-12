library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;

entity fourbit is 
	port(
			a,b:in std_logic_vector(3 downto 0);
			s: out std_logic_vector(3 downto 0);
			c:out std_logic
		);
end fourbit;
architecture fourbit_arch of fourbit is

component fa is
	port(
			p,q,cin:in std_logic;
			s,c:out std_logic
		);
end component;

signal v1,v2,v3: std_logic;

begin
	M1:fa port map (a(0),b(0),'0',s(0),v1);
	M2:fa port map (a(1),b(1),v1,s(1),v2);
	M3:fa port map (a(2),b(2),v2,s(2),v3);
	M4:fa port map (a(3),b(3),v3,s(3),c);
end fourbit_arch;
