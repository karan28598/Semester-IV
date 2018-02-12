library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;
entity and is
port( 
	x,y:in std_logic;
    z:out std_logic
    );
end and;
architecture and_arch of and is begin
z<=x and y;
end and_arch;