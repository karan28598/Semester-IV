library ieee;
use ieee. std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;

entity johnson_counter is
port (
	d: in std_logic_vector(3 downto 0);
	rst,clk: in std_logic;
	q, q_b: out std_logic_vector(3 downto 0)
);
end johnson_counter;
architecture structure of johnson_counter is
component d_ff is 
port
(
            d, clk, rst: in std_logic;
	q,q_b: out std_logic
);
end component;
signal q_s: std_logic_vector(3 downto 0);
signal q_bs: std_logic_vector(3 downto 0);
begin
T1: d_ff port map(q_bs(3),clk,rst,q_s(0),q_bs(0));
T2: d_ff port map(q_s(0),clk,rst,q_s(1),q_bs(1));
T3: d_ff port map(q_s(1),clk,rst,q_s(2),q_bs(2));
T4: d_ff port map(q_s(2),clk,rst,q_s(3),q_bs(3));
q<= q_s;
q_b<= q_bs;
end structure;
