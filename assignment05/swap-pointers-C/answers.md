# Qs & As  

Create a function in “C” that allows swapping of two pointers.  
a. Explain what the “main” function does in order to setup the input arguments prior to 
calling the swap_pointer() function?
#### The main function does the following actions to set up the input arguments for the swap_pointer() function:  
#### #1. Declare int variables x & y, and assign them initial values:
    int x = 2000000;
    int y = 1000000;  
#### #2. Declare int* variables for x and y, and assign them the memory addresses (pointers) for x and y:  
    int* xPtr;
    xPtr = &x;
    int* yPtr;
    yPtr = &y;  
#### #3. Declare int** variables for x and y, and assign them the memory addresses (pointers) to pointers for x and y:  
    int** PtrxPtr;
    int** PtryPtr;
    PtrxPtr = &xPtr;
    PtryPtr = &yPtr;  
#### #4. "main" function is now ready to pass the arguments 'PtrxPtr' and 'PtryPtr' to the swap_pointer() function.  

b. What are the values in R0 & R1 when swap_pointer() is called?  
#### When swap_pointer() is called, R0 & R1 have the arguments that are passed on by "main" to the swap_pointer() function.  
#### In this case the values passed are the the poniers to pointers for x and y, i.e., PtrxPtr and PtryPtr.  
    swap_pointer(PtrxPtr, PtryPtr);
   ![ro-r1](https://github.com/isjosan/embsys310/blob/master/assignment05/swap-pointers-C/images/r0-r1.PNG)  
   
   Screen shot of the local variables inside of "main" before the function is called:
   ![before-swap]()
c. Share a screen shot of the local variables inside of “main” after the function 
swap_pointer() returns showing the values of the pointers and what they are pointing to  
#### The
