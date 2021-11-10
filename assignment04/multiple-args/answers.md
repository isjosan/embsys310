## Qs & As  

Create a function “func1” with 5 arguments and call “func1” from within another function
“func2”. Trace thru the assembler and note:  

a. How does the calling function “func2” pass the values to the called function “func1”?  
### The calling function func2 first initializes R4 - R8 with the argument values. Then, it moves the values from R4 - R7 to R0 - R3. However, the value in R8 is pushed to the stack.

![func2](https://github.com/isjosan/embsys310/blob/master/assignment04/multiple-args/images/func2.PNG)

b. What extra code did the compiler generate before calling the function “func1” with the
multiple arguments?  

c. What extra code did the compiler generate inside the called function “funct1” with the
list of multiple arguments?  

d. Any other observations?  

