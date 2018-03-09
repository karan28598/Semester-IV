library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;

entity pencoder is
   port(i:in std_logic_vector(7 downto 0);
        o:out std_logic_vector(2 downto 0));
end pencoder;

architecture pencoder_arch of pencoder is
   begin
      process(i)
         variable n:integer range 0 to 7;c
         begin
            for j in 7 downto 0 loop
               if(i(j)='1') then
                  n:=j;
                  exit;
               end if;   
            end loop;
            o<=conv_std_logic_vector(n,3);
      end process;            
end pencoder_arch;
