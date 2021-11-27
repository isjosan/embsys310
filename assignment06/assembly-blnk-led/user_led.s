/*******************************************************************************
File name       : user_led.s
Description     : Assembly language function for controlling the user LED
*******************************************************************************/   

    EXTERN delay                    // delay() is defined outside this file

    PUBLIC control_user_led1        // Exports symbols to other modules

// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables. The syntax for declaring bss section is -
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
Function Name   : control_user_led1
Description     : - Uses Peripheral registers at base 0x4800.0000
                    to set GPIOA Output Data Register.
                  - Calls another assembly function delay to insert
                    delay loop

C Prototype     : void control_user_led(uint8_t state, uint32_t duration)
                : Where state indicates if LED should be on or off.
Parameters      : R0: uint8_t state
                : R1: uint32_t duration
Return value    : None
*******************************************************************************/  

GPIOA_BASE  EQU 0x48000000
GPIOA_ODR   EQU 0x14
GPIOA_BIT_5 EQU 0x20

control_user_led1
            PUSH     {LR}                     // Save LR on the stack
            MOV      R2, #GPIOA_BASE          // Move GPIOA Base Address to R2
            LDR      R3, [R2, #GPIOA_ODR]     // Load R3 with contents of memory from address poinyted by the sum of R2 and the GPIOA_ODR
            CBZ      R0, led_off              // Compare the contents of first argument in R0 with 0 (LED_OFF); if true branch to instruction with label led_off
led_on:     ORRS.W   R3, R3, #GPIOA_BIT_5     // Bitwise OR the contents of R3 with GPIO_BIT_5 and store the result in R3 ; to turn the LED ON
            B        delay_prep               // Branch to the instruction with label delay_prep
led_off:    BICS.W   R3, R3, #GPIOA_BIT_5     // BItwise clear R3 with the complement of GPIOA_BIT_5 and store the result in R3      
delay_prep: STR      R3, [R2, #GPIOA_ODR]     // Store the contents of R3 in memory with address pointed to by the sum of R2 (GPIO_BASE) and the offset (GPIOA_ODR)
            PUSH     {R0 - R3, LR}            // Save the contents of R0-R3 and LR on stack before calling delay subroutine
            MOV      R0, R1                   // Move the contents of R1 (duration argument from main) to R0 (to pass on argument to delay subroutine)
call_delay: B        delay                    // Branch to delay subroutine in assembly
            POP      {R0 - R3, LR}            // After return from delay assembly subroutine, restore the registers R0-R3 and LR for return to main program
exit:       BX       LR                       // Branch indirect; return from function call
    
    END
