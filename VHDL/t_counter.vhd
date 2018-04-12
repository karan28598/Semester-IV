Library ieee;
use ieee. std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;

entity t_counter is
port (
	t, clk, rst: in std_logic;
	q, q_bar: out std_logic
);
End t_counter;

architecture behave of t_counter is
signalq_s: std_logic;
begin

process(clk, rst, t)
begin
if (rst='0')then
q_s<= '0';
elsif (clk' event and clk<='0')then 
if (t='1')then 
q_s<= not q_S;
end if;
end if;
