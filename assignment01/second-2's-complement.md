#                               Usage of 2's complement

All Central Processing Units (CPUs) in computers use 2's complement to represent negative numbers in arithmetic operations. The reason is that the subtraction of a number is the same as adding the 2's complement of the number.  

For example, let us assume that we need to subtract decimal 2 from  decimal 12, that is, we need to perform the arithmetric subtraction (12 - 2).

Now, decimal 12 is represented in binary as 0000 1100  
and, decimal 2  is represented in binary as 0000 0010

Converting 0000 0010 to its 2's complement, we have  
(1111 1101 + 0000 0001) = 1111 1110  

Now adding 2's complement of decimal 2 to binary 12, we have:  
(0000 1100 + 1111 1110) = 0000 1010 (decimal 10)

that is, (12 - 2) is indeed equal to 10, when representing 2 as 2's complement and adding it to binary 12.

So, a digital adder circuit can also be used for subtraction, if the 2's comlement of the number to be subtracted is simply added.   
There is no need to design separate digital circuits for subtraction.   
This property of 2's complement representation of negative numbers results in simplifying the digital circuitry for arithmetic operations.


