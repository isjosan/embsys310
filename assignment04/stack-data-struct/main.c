#include "stack.h"
#include "test.h"

int main(void)
{
    stack_init();
    int push_data = -54; 
    stack_push(push_data);
    int pop_data = stack_pop();
    
    return 0;
}
