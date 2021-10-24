# Qs & As
1. Inject 0x7FFFFFFF for the “counter” value in the variable window, then step thru the program   
   only once to increment “counter”.  
   a) What is the value of the “counter” from the “Locals” window?  
      ## -2'147'483'648
   b) What is the value of the “counter” in the “Registers” window?  
      ## 0x8000'0000
   c) Please note down which flags are set in the APSR register. And explain why.  
      ## N (Negative), V (Overflow)
      ### N flag is set because msb (bit 31) is set to 1, and that indicates a negative value.
      ### V flag is set because there is an overflow condition when 0x7FFFFFFF value is incremented by 1, indicating that the result does not fit in the number of bits available. (0x7fffffff + 1) results in a 2's complement (negative number) of 0x7fffffff), that is 0x 0107fffffff, so the overflow bit 32, cannot be accomodated in the available word size of 32 bits(bit 0 to bit 31).
   
2. If your write all Fs (0XFFFFFFFF) in the Register value for “counter” then step thru the program  
   once to increment “counter”  
   a) What happens to the value of “counter” in the “Locals” window?  
      ### The value of counter becomes '0' after increment.
      
   b) Please note down which are set in the APSR register. And explain why.  
      ### Z (Zero) flag is set, because the contents of Register R1 are 0x0000.
      ### C (Carry) flag is set, because when (0xffffffff + 1) was executed, it resulted in a Carry bit off bit 31.
   
3. Change the “counter” variable type in your code to “unsigned int”. Inject the values  
   “0x7FFFFFFF” then step thru the program to increment the “counter” once:  
   a) What is the value of “counter” in the “Locals” window after incrementing for each value?  
      ## 2'147'483'648
     
   b) Please note down which flags are set in the APSR register. And explain why.  
      ### N (Negative), V (Overflow), after first increment
      ### N (Negative) after second increment
      ### N flag is set because msb (bit 31) is set to 1; although counter is declared unsigned int, still N flag is set to 1 as it is the msb (bit 31), that is intended to be sign bit for negative integers (2's complement representation).
      ### V flag is still set in the first increment, but gets cleared in the second incremeent, as now only positive integers are counted, bit 31 loses its meaning as a sign bit. 
 4. Change the “counter” variable type in your code to “unsigned”. Inject the values “0xFFFFFFFF”  
    then step thru the program to increment the “counter” once:  
    a) What is the value of “counter” in the “Locals” window after incrementing for each value?  
    ## 4'294'967'295  
    b) Please note down which are set in the APSR register. And explain why.  
    ### N (negative) flag is set, because the msb (bit 31) is set to 1, although the value is interpreted as that of a unsigned int, and the signed bit is ignored.
  
 5. Move the “counter’ variable outside of main (at the top of the file):  
     
     a) What is the scope of the variable “counter”?  
     ### The "counter" variable now has 'file scope', that extends from its point of declaration to the end of file 'main.c'.  
     
     b) Is it still visible in the “Locals” view?  
     ### No, it is not, because it is no longer a 'local' variable.
   
     c) In which window view can we track “counter” now?  
     ### Variable 'counter' can now be tracked in 'Watch' window.
   
     d) What is the address of the “counter” variable in memory?  
     ### Address of the 'counter' variable in memory is 0x20000000.
   
 6. Change the source code to the following, then run the program in the simulator:  
      int counter = 0x0;  
      int main() {  
      int *p_int = (int *)0x20000000;  
      ++(*p_int);  
      ++(*p_int);
      ++(*p_int);  
      counter ++;  
      return 0;  
      }  
     a) What is the value of “counter” at the end of the program (halting at the return 0 statement)  
     ### The value of "counter" at the end of the program is '4'.   
  
     b) Explain why the counter value has changed?  
     ### The counter value has changed because the pointer variable *p_int stores the memory address 0x20000000 where the "counter" value is stored. In the program, the *p_int is dereferenced 3 times and incremented each time, that is, the counter value stored at the address in *p_int is incremented 3 times. Subsequently, the counter++ statement increments the counter value 1 more time. The total counter value is 4 at the end of the program.  
     
   7. Change the setting of IAR to run the same program on the evaluation board:  
      a) What is the address where “counter” is stored?  
     
      b) Is the “counter” variable stored in RAM or ROM?  
     
      c) What is the value of “counter” at the end of the program (halting at the return 0  
        statement).
 
  
  


