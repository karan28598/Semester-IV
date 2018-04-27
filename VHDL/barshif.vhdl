function shift (i:in std_logic_vector(7 downto 0);
                sft:in std_logic_vector(2 downto 0);
                s:in std_logic_vector(1 downto 0)) 
return std_logic_vector is 
variable t:std_logic_vector(7 downto 0);
variable t1:integer range 0 to 7;          
    begin
    t:=i;
    t1:=conv(sft);
    case s is
       when "00" =>
          for i in 0 to 7 loop
          if i<t1 then
             t:=t(6 downto 0) & '0';
          end if;   
          end loop;
       when "01" =>
          for i in 0 to 7 loop
          if i<t1 then
             t:='0' & t(7 downto 1);
          end if;   
          end loop;
       when "10" =>
          for i in 0 to 7 loop
          if i<t1 then
             t:=t(6 downto 0) & t(7);
          end if;   
          end loop;
       when "11" =>
          for i in 0 to 7 loop
          if i<t1 then
             t:=t(0) & t(7 downto 1);
             end if;
          end loop;
       when others=>
          t:="00000000";   
       end case;
       return t;                        
end shift;  
begin
   o<=shift(i,sft,s);
end barshif_arch;