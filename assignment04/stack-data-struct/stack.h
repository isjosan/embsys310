// Interface file to declare functions for  an Ascending Stack (LIFO) data structure

#ifndef __STACK_H__
#define __STACK_H__

#include <stdbool.h>
#include <limits.h>

// Length of the Stack-max number of integers that can be stored
enum {STACK_SIZE = 10};

extern int* stack_pointer;
extern int* stack_top;
extern int* stack_bottom;
extern int stack[STACK_SIZE];
extern int push_data;
extern int pop_data;
extern bool isEmpty;
extern bool isFull;


//Function Prototypes

// Initialize Stack Internals and returns bottom_of_stack pointer
extern int stack_init(void);

//Push an element onto the Stack
extern int stack_push(int data);

// Pop an element off the Stack
extern int stack_pop(void);

// Check if the Stack is empty
extern int stack_isEmpty(void);

// Check if the Stack is full
extern int stack_isFull(void);

#endif