/*******************************************************************************
File name       : swapCharsAsm.s
Description     : Assembly language function to swap 2 characters
*******************************************************************************/   

    EXTERN PrintString  // PrintString is defined outside this file.
    EXTERN myCstr       // myCstr defined outside this file.
    
    PUBLIC swapCharsAsm // Exports symbols to other modules
                        // Making swapCharsAsm available to other modules.
    
// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables.
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.

// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : swapCharsAsm
Description     : Calls C code to print a string; 
                  swaps 2 character data types
C Prototype     : void swapCharsAsm(char1*, char2*)
                : Where val is the value to be divided by 2.
Parameters      : R0: integer val
Return value    : R0
*******************************************************************************/  
  
swapCharsAsm
    PUSH {R0-R3, LR}    // save the input arguments and return address
    LDR R0, =myCstr     // load (global) address of address of string into R0
    LDR R0, [R0]        // Load address of string into R0
    BL  PrintString     // call PrintString to print the string
    POP {R0-R3, LR}     // Restore R0, R1 and LR
    LDRB R2, [R0]        // Load R2 with memory contents pointed by first agrument address in R0
    LDRB R3, [R1]        // Load R3 with memory contents ponied by second argument address in R1
    STRB R3, [R0]        // Store R3 at memory address pointed by 1st  argument address in R0
    STRB R2, [R1]        // Store R2 at memory address pointed by 2nd argument address in R1.
    BX  LR              // return
    
    END

/*
