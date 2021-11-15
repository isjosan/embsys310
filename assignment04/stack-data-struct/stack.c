// Implementation file for Stack (LIFO) functions
#include "stack.h"

bool isEmpty = false;
bool isFull = false;

int stack_init()
{
    // Initialize elements of stack
    int count = 0;
    for(count = 0; count < STACK_SIZE; ++count)
    {
        stack[count] = 0;
    }
    stack_bottom = &stack[0];
    stack_top = stack_bottom + STACK_SIZE;   
    stack_pointer = stack_bottom;
    isEmpty = true;
    
    return 0;
}

int stack_push(int push_data)
{
    //In limits.h, INT_MIN is <= -32767; INT_MAX is >= 32767
    // Check for Integer bounds
    if(push_data >= 32767) return -1; 
    if(push_data <= -32767) return -1;
    if(isFull == true) return -1; //Check if the stack is full
    *stack_pointer = push_data;
    ++stack_pointer;
    stack_isFull();
    stack_isEmpty();
    if(stack_pointer > stack_top) return -1;
    return 0;
}

int stack_pop(void)
{
    if(isEmpty == true) return -1; //Check if the stack is Empty.
    --stack_pointer;
    stack_isFull();
    stack_isEmpty(); 
    if(stack_pointer < stack_bottom) return -1;
    pop_data = *stack_pointer;
    *stack_pointer = 0;
    
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


        
    

