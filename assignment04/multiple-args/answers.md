## Qs & As  

Create a function “func1” with 5 arguments and call “func1” from within another function
“func2”. Trace thru the assembler and note:  

a. How does the calling function “func2” pass the values to the called function “func1”?  
### The calling function func2 first initializes R4 - R8 with the argument values. Then, it moves the values from R4 - R7 to R0 - R3. However, the value in R8 is pushed to the stack.

![func2](https://github.com/isjosan/embsys310/blob/master/assignment04/multiple-args/images/func2.PNG)

b. What extra code did the compiler generate before calling the function “func1” with the
multiple arguments?  
### The compiler generated extra code to PUSH R4-R5 to the stack. Then, a Load was done on R4, with the contents of stack memory location pointed to by (SP + 0x08), that is actually the same location where the 5th argument passed to func1 was pushed, as shown in the first 2 instructions at the top of the snippet below:
![func1](https://github.com/isjosan/embsys310/blob/master/assignment04/multiple-args/images/func1.PNG)  


c. What extra code did the compiler generate inside the called function “funct1” with the
list of multiple arguments?  
#### Inside the called function, func1 (as shown in the snippet above), for each array element, first the address of the array element (pointer) is loaded into R5 with LDR.N, next STR instruction is used to Store the argument values stored in R0 - R4 into the memory location pointed to by the address in R5.

d. Any other observations?  

