// Implementation file for Stack (LIFO) functions
#include <stdbool.h>
#include "stack.h"

static int stack[STACK_LEN];
int* stack_pointer;
int* stack_base;
int* stack_top;
int push_data;
int pop_data;
bool isEmpty = false;
bool isFull = false;

int stack_init()
{
    // Initialize all elements of Stack Array to 0
    unsigned int count = 0;
            
    for(count = 0; count <= STACK_LEN; ++count)
    {
        stack[count] = 0;
    }
    // Initialize stack pointer to the bottom of the stack at array element with index 0
     
    stack_base = &stack[0];
    stack_top = stack_base + STACK_LEN + 1;
    stack_pointer = stack_base;
    
    return 0;
}

int stack_push(int push_data)
{
    *stack_pointer = push_data;
    ++stack_pointer;
    return 0;
}

int stack_pop(void)
{
    --stack_pointer;
    pop_data = *stack_pointer;
    *stack_pointer = 0;
    return pop_data;
}

bool stack_isEmpty(void)
{
    
    return isEmpty;
}


        
    

