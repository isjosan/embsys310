#include "stack.h"
#include "main.h"
#include <assert.h>
#include <stddef.h>

int* stack_pointer = NULL;
int* stack_top = NULL;
int* stack_bottom = NULL;
int stack[STACK_SIZE] = {NULL};
int push_data = NULL;
int pop_data = NULL;

int main(void)
{
    init_stack_internals(); 
    push_positive_int();
    pop_positive_int();
    push_negative_int();
    pop_negative_int();
    push_null();
    pop_null();
    push_multiple_int();
    pop_multiple_int();
    lower_bound_int();
    upper_bound_int();
    lower_bound_stack();
    upper_bound_stack();
    
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
    int count = 0;
    for(count = 0; count < STACK_SIZE; ++count)
    {
        assert(stack[count] == NULL);
    }
    assert(stack_pointer != NULL);
    assert(stack_pointer == stack_bottom);
    assert(stack_top == stack_bottom + STACK_SIZE);
    assert(isEmpty == true);
    assert(isFull == false);
    
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

// Test8: Successfully Push multiple large negative, positive and null int elements to the Stack.

void push_multiple_int(void)
{
    // Arrange(setup)
    int push_multiple[STACK_SIZE]= {1, -1, 0, 32766, -32766, 0, 0, 12345, 23456, -23456};
    
    // Act(execute)
    int count = 0;
    for(count = 0; count < STACK_SIZE; ++count)
    {
        push_data = push_multiple[count];
        stack_push(push_data);
    }
    
    // Assert(verify)
    assert(stack_pointer == stack_top);
    assert(isFull == true);
    assert(isEmpty == false);       
}

// Test9: Successfully Pop multiple large negative, positive and null int elements from the Stack in reverse order.

void pop_multiple_int(void)
{  
    // Arrange(setup)
    int push_multiple[STACK_SIZE]= {1, -1, 0, 32766, -32766, 0, 0, 12345, 23456, -23456};
    int pop_multiple[STACK_SIZE] = {NULL};
    
    // Act(execute)
    int count = 0;
    for(count = STACK_SIZE -1; count >= 0; --count) //Popped elements are in reverse order
    {
        pop_data = stack_pop();
        pop_multiple[count] = pop_data;
    }
        
    // Assert(verify)
    for(count = 0; count < STACK_SIZE; ++count)
    {
        assert(push_multiple[count] == pop_multiple[count]);
    }
        assert(isFull == false);
        assert(isEmpty == true);
        assert(stack_pointer == stack_bottom);
}
// Test10: Test lower bounds of Pushed integer value

void lower_bound_int(void)
{
    // Arrange(setup)
    //In limits.h, INT_MIN is <= -32767; INT_MAX is >= 32767
    //Check for lower bound, INT_MIN 
    push_data = -32767; // This Push should fail
    
    // Act(execute)
    stack_push(push_data);
    
    // Assert(verify)
    assert(push_data != stack[0]);
    assert(stack_pointer != stack_bottom + 1);
    assert(isEmpty == true);
    assert(isFull == false);    
}
// Test 11: Test upper bound of Pushed integer value

void upper_bound_int(void)
{
    // Arrange(setup)
    //In limits.h, INT_MIN is <= -32767; INT_MAX is >= 32767
    //Check for upper bound, INT_MAX
    push_data = 32767; // This Push should fail
    
    // Act(execute)
    stack_push(push_data);
    
    // Assert(verify)
    assert(push_data != stack[0]);
    assert(stack_pointer != stack_bottom + 1);
    assert(isEmpty == true);
    assert(isFull == false);    
}

// Test12: Successfully test Error condition, when lower bound of the Stack is breached.

void lower_bound_stack(void)
{  
    // Arrange(setup)
    stack_init();
    
    // Act(execute)
    stack_pop(); // This Pop should fail.
    
    // Assert(verify)
    assert(stack_pointer == stack_bottom);
    assert(isEmpty == true);
    assert(isFull == false);
}
// Test13: Successfully test Error condition when upper bound of the Stack is breached.

void upper_bound_stack(void)
{    
    // Arrange(setup)
    stack_init();
    int push_multiple[STACK_SIZE]= {1, -1, 0, 32766, -32766, 0, 0, 12345, 23456, -23456};
    
    // Act(execute)
    int count = 0;
    for(count = 0; count < STACK_SIZE; ++count)
    {
        push_data = push_multiple[count];
        stack_push(push_data);
    }
    stack_push(push_data); //This Push should fail.
    
    // Assert(verify)
    assert(stack_pointer == stack_top);
    assert(isEmpty == false);
    assert(isFull == true);
}