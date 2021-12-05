# Qs & As 
### 2. Generate the map file for your program and provide details on:  

a. How much total ROM your program is occupying?
####   The program is occupying 456 bytes of total ROM, out of which 374 bytes are for read-only code and 82 bytes are for read-only data.

b. How much total RAM your program is using?  
####   The program is occupying 8196 bytes of total RAM, out of which 4 bytes are for read-write data for global variable (uint32_t delayInMilliseconds) defined in main.c and 8192 bytes are linker created for configured stack memory (CSTACK size: 0x2000).

c. What part of your program is using the most ROM?  
####   The object code for main.c is the largest in size at 124 bytes and occupies the ROM.

d. What part of your program is using the most RAM?  
#### The linker created memory locations in RAM for CSTACK are the largest at 8192 bytes.  

3. Bonus: Is there anything that can be done to optimize the usage of ROM or RAM resources? 
Explain any options that you come up with.
### 3.1 Optimize the size of ROM  
#### The code in main.c and delay.c can be written entirely in assembly, as it implements a simple function of programming the RCC, GPIO and SysTick related registers, and then implementing an infinite loop to toggle the LED. The pure assembly code size is expected to be significantly smaller in size than the one written in C.  

### 3.2 Optimize the size of RAM
#### The following changes were implemented and tested successfully to reduce the total RAM occupied by the program to 130 bytes ( 2 for global variable + 128 for CSTACK):  
#### 3.2.1 The type of global variable delayInMilliseconds was changed from uint32_t to uint16_t, reducing the size of read-write data for global variable from 4 to 2.
#### 3.2.2 The CSTACK size configured in IAR Linker was reduced from default 0x2000 to a lower value of 0x80, reducing the size of read-write data for CSTACK from 8192 to 128.


