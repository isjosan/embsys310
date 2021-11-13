// Implementation file for Stack (LIFO) functions
#include "stack.h"
#include <stdbool.h>
#include <limits.h>


int* stack_pointer;
int* stack_top;
int* stack_bottom;
int push_data;
int pop_data;
bool isEmpty = false;
bool isFull = false;

int stack_init()
{
    // Initialize elements of stack
    static int stack[STACK_LEN] = {0}; 
    stack_bottom = &stack[0];
    stack_top = stack_bottom + STACK_LEN;   
    stack_pointer = stack_bottom;
    
    return 0;
}

int stack_push(int push_data)
{
    *stack_pointer = push_data;
    stack_isFull();
    ++stack_pointer;
    if(stack_pointer > stack_top) return -1;
    return 0;
}

int stack_pop(void)
{
    --stack_pointer;
    if(stack_pointer < stack_bottom) return -1;
    pop_data = *stack_pointer;
    *stack_pointer = 0;
    stack_isEmpty(); 
    
    return pop_data;
}

int stack_isFull(void)
{
    (stack_pointer == stack_top) ? (isFull = true) : (isFull = false);
    return isFull;
}

int stack_isEmpty(void)
{
    (stack_pointer == stack_bottom) ? (isEmpty = true) : (isEmpty = false);
    return isEmpty;
}


        
    

