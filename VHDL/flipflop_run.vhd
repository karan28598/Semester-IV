library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;

entity flipflop_run is
port(D,C,CL:in std_logic;
     Q: out std_logic);
end entity;
architecture behavioural of flipflop_run is
type state is(zero,one);
signal prev,nxt:state;
begin
   process(C,CL)
   begin
      if(CL='0') then
         prev<=zero;
      elsif(C'event and C='1') then
         prev<=nxt;
      end if;
   end process;
   process(prev,D)
   begin
      case prev is
         when zero=>
         Q<='0';
         if(D='0') then
            nxt<=zero;
         else
            nxt<=one;
         end if;
         when one=>
         Q<='1';
         if(D='0') then
            nxt<=zero;
         else
            nxt<=one;
         end if;
      end case;                        
   end process;
end behavioural;