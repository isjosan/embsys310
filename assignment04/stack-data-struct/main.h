// Interface file for unit test functions

#ifndef __MAIN_H__
#define __MAIN_H__

//TEST1: Successfully Push an unsigned int element to the Stack

void push_unsigned_int(void);

//Test2: Successfully Pop an unsigned int int element from the Stack

void pop_unsigned_int(void);

//TEST3: Successfully Push a signed negative int element to the Stack

void push_signed_int(void);

//TEST4: Successfully Pop a signed negative int element from the Stack

void pop_signed_int(void);

//TEST5: Successfull Push a NULL to the Stack.

void push_null(void);

//TEST6: Successfully Pop a NULL from the Stack.

void pop_null(void);

//TEST7: Successfully Push multiple Large unsigned int to the Stack

void push_multiple_unsigned_int(void);

//TEST8: Successfully Pop multiple Large unsigned int elements from the Stack in revers order.

void pop_multiple_unsigned_int(void);

//TEST9: Successfully Push multiple Large negative signed int elements to the Stack.

void push_multiple_signed_int(void);

//TEST10: Successfully Pop multiple Large negative signed elements from the Stack in reverse order.

void pop_multiple_signed_int(void);

//TEST11: Successfully Push a char element to the stack.

void push_char(void);

//TEST12: Successfully Pop a char element from the stack.

void pop_char(void);

//Test13: Successfully initialize the Stack internals.

void init_stack_internals(void);

//Test14: Successfully test Stack Empty condition.

void stack_empty(void);

//Test15: Successfully test Stack Full condition.

void stack_full(void);

//Test16: Successfully test error condition, when lower bound of stack is breached.

void stack_lower_bounds(void);

//Test17: Successfully test error condition when upper bound of stack is breached.

void stack_upper_bounds(void);

#endif
