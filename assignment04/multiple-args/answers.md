## Qs & As  

Create a function “func1” with 5 arguments and call “func1” from within another function
“func2”. Trace thru the assembler and note:  

a. How does the calling function “func2” pass the values to the called function “func1”?  
### The calling function func2 first initializes R4 - R8 with the argument values. Then, it moves the values from R4 - R7 to R0 - R3. However, the value in R8 is stored at the stack pointer address pointed by SP.

![func2](https://github.com/isjosan/embsys310/blob/master/assignment04/multiple-args/images/func2.PNG)

b. What extra code did the compiler generate before calling the function “func1” with the
multiple arguments?  
### The compiler generated extra code to PUSH R4-R5 to the stack. Then, a Load was done on R4, with the contents of stack memory location pointed to by (SP + 0x08), that is actually the same location where the 5th argument passed to func1 was pushed, as shown in the first 2 instructions at the top of the snippet below:
![func1](https://github.com/isjosan/embsys310/blob/master/assignment04/multiple-args/images/func1.PNG)  


c. What extra code did the compiler generate inside the called function “funct1” with the
list of multiple arguments?  
#### Inside the called function, func1 (as shown in the snippet above), for each array element, first the address of the array element (pointer) is loaded into R5 with LDR.N, next STR instruction is used to Store the argument values stored in R0 - R4 into the memory location pointed to by the address in R5 plus the 4-byte address offset for each int element in the array.

d. Any other observations?  

#### #1. In the initial reset position in the debugger, the CSTACK shows the data word 0xFEF5EDA5 at the following 2 addresses:  

![cstack](https://github.com/isjosan/embsys310/blob/master/assignment04/multiple-args/images/cstack.PNG)  

#### The 'Armv8-M Secure Stack Sealing' document from ARM mentions that "Arm recommends that both the Secure Process and the Secure Main stack pointer have a special value, 0xFEF5EDA5, added to the top of the stack. This prevents an attacker using a fake FNC_RETURN or EXC_RETURN to enter the Secure world."  

#### #2. The first instruction when the program enters main() is a PUSH of R7 & LR to the stack (snippet below). It is not clear, why only R7 should be Pushed to the stack and not other Registers.
![obsrv1](https://github.com/isjosan/embsys310/blob/master/assignment04/multiple-args/images/obsrv1.PNG)  
#### #3. The first instrcution when the program enters func2() is a PUSH of R2-R8 & LR to the stack, before R4-R8 are initialized with the argument values (snippet above).  

#### #4. At the return statement in main(), the R0 is initialized with the return value '0' and the POP instruction restores the R1 and PC values from the stack(snippet below). This is different from the case when function call returns, it is the LR value that is used to branch off to the next instruction in the program flow.  

![return](https://github.com/isjosan/embsys310/blob/master/assignment04/multiple-args/images/return.PNG)  







