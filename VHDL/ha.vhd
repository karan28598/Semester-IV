library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;

entity ha is
port (
		  x,y: in std_logic;
		  u,v:out std_logic
      );
end ha;

architecture ha_arch of ha is
begin
	u<=x xor y;
	v<=x and y;
end ha_arch;