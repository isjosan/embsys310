#include "stack.h"
#include "main.h"
#include <assert.h>
#include <stddef.h>

int* stack_pointer = NULL;
int* stack_top = NULL;
int* stack_bottom = NULL;
int stack[STACK_SIZE] = {NULL};
int push_data = 0;
int pop_data = 0;

int main(void)
{
    init_stack_internals(); 
    push_positive_int();
    pop_positive_int();
    push_negative_int();
    pop_negative_int();
    push_null();
    pop_null();
    return 0;
}

// Test1: Successfully initialize the Stack internals.

void init_stack_internals(void)
{
    // Arrange(setup)
    // STACK_SIZE = 10, pre-defined in __STACK_H__
   
    // Act(execute)
    stack_init();
    
    // Assert(verify)
    assert(stack_pointer == stack_bottom);
    assert(stack_top == stack_bottom + STACK_SIZE);
    assert(stack[0] == NULL);
    assert(stack[STACK_SIZE - 1] == NULL);
    assert(isEmpty == true);
}

// Test2: Successfully Push an unsigned int element to the Stack.

void push_positive_int(void)
{
    // Arrange(setup)
    push_data = 12345;
    
    // Act(execute)
    stack_push(push_data);
    
    // Assert(verify)
    assert(push_data == stack[0]);
    assert(stack_pointer == stack_bottom + 1);
    assert(isEmpty == false);
    assert(isFull == false);
}

// Test3: Successfully Pop an unsigned int element from the Stack.

void pop_positive_int(void)
{
    // Arrange(setup)
    pop_data = 0;
    
    // Act(execute)
    pop_data = stack_pop();
    
    // Assert(verify)
    assert(pop_data == push_data);
    assert(stack_pointer == stack_bottom);
    assert(isEmpty == true);
    assert(isFull == false);
    
}

// Test4: Successfully Push a negative int element to the Stack.

void push_negative_int(void)
{
    // Arrange(setup)
    push_data = -12345;
    
    // Act(execute)
    stack_push(push_data);
    
    // Assert(verify)
    assert(push_data == stack[0]);
    assert(stack_pointer == stack_bottom + 1);
    assert(isEmpty == false);
    assert(isFull == false);
}

// Test5: Successfully Pop a negative int element from the Stack.

void pop_negative_int(void)
{
     // Arrange(setup)
    pop_data = 0;
    
    // Act(execute)
    pop_data = stack_pop();
    
    // Assert(verify
    assert(pop_data == push_data);
    assert(stack_pointer == stack_bottom);
    assert(isEmpty == true);
    assert(isFull == false);
}

// Test6: Successfully Push a NULL element to the Stack.

void push_null(void)
{
    // Arrange(setup)
    push_data = NULL;
    
    // Act(execute)
    stack_push(push_data);
    
    // Assert(verify)
    assert(push_data == stack[0]);
    assert(stack_pointer == stack_bottom + 1);
    assert(isEmpty == false);
    assert(isFull == false);
}

// Test7: Successfully Pop a NULL element from the Stack.

void pop_null(void)
{
    // Arrange(setup)
    pop_data = 0;
    
    // Act(execute)
    pop_data = stack_pop();
    
    // Assert(verify)
    assert(pop_data == push_data);
    assert(stack_pointer == stack_bottom);
    assert(isEmpty == true);
    assert(isFull == false);
}