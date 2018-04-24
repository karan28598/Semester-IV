library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;

entity sdet is
port(clr,clk,i:in std_logic;
     q:out std_logic);
end sdet;

architecture sdet_arch of sdet is
type state is(a,b,c,d,e);
signal prev,nxt:state;
begin
   process(clr,clk)
   begin
      if(clr='0') then
         prev<=a;
      elsif(clk'event and clk='1') then
         prev<=nxt;
      end if;
   end process;
   process(prev,i)
   begin
      case prev is
         when a=>
            q<='0';
            if(i='0') then
               nxt<=a;
            elsif(i='1') then
               nxt<=b;
            end if;
         when b=>
            q<='0';
            if(i='0') then
               nxt<=a;
            elsif(i='1') then
               nxt<=c;
            end if;
         when c=>
            q<='0';
            if(i='0') then
               nxt<=d;
            elsif(i='1') then
               nxt<=c;
            end if;
         when d=>
            q<='0';
            if(i='0') then
               nxt<=a;
            elsif(i='1') then
               nxt<=e;
            end if;
         when e=>
            q<='1';
            if(i='0') then
               nxt<=a;
            elsif(i='1') then
               nxt<=c;
            end if;
      end case;
   end process;
end sdet_arch;