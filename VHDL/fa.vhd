library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
entity fa is
port(
	p,q,cin:in std_logic;
	s,c:out std_logic
	);
end fa;
architecture fa_arch of fa is
component ha is
port( x,y:in std_logic;
	u,v:out std_logic);
end component;
signal s1,s2,s3:std_logic;
begin
m1:ha port map (p,q,s1,s2);
m2:ha port map (s1 ,cin,s,s3);
c<= s2 or s3;
end fa_arch;