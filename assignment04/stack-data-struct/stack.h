// Interface file to declare functions for  an Ascending Stack (LIFO) data structure

#ifndef __STACK_H__
#define __STACK_H__

// Length of the Stack-max number of integers that can be stored
enum {STACK_LEN = 10};

//Function Prototypes

// Initialize Stack Internals and returns bottom_of_stack pointer
int stack_init(void);

//Push an element onto the Stack
int stack_push(int data);

// Pop an element off the Stack
int stack_pop(void);

// Check if the Stack is empty
int stack_isEmpty(void);

// Check if the Stack is full
int stack_isFull(void);

#endif