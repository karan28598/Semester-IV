Library ieee;
Use ieee. std_logic_1164.all;
Use ieee. std_logic_unsigned.all;
Entity updown is
       port(t,clk,rst:instd_logic;
              q:out std_logic_vector(3 downto 0));
end entity;
architecture updown_arch of updown is
signal s: std_logic_vector(3 downto 0);
begin
process(clk,rst)
begin
if(rst='1')then
s<="0000";
elsif(clk' event and clk='1')then
if (t='1')then
s<=s+1;
else
s<=s-1;
end if;
end if;
end process;
q<=s;
end updown_arch;