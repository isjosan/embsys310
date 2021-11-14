// Interface file for Unit Test functions

#ifndef __MAIN_H__
#define __MAIN_H__

// Test1: Successfully initialize the Stack internals.

extern void init_stack_internals(void);

    // Arrange(setup)
    
    // Act(execute)
    
    // Assert(verify)

// Test2: Successfully Push an positive int element to the Stack.

extern void push_positive_int(void);
        
    // Arrange(setup)
    
    // Act(execute)
    
    // Assert(verify)

// Test3: Successfully Pop an positive int element from the Stack.

extern void pop_positive_int(void);

    // Arrange(setup)
    
    // Act(execute)
    
    // Assert(verify)

// Test4: Successfully Push a negative int element to the Stack.

extern void push_negative_int(void);
    
    // Arrange(setup)
    
    // Act(execute)
    
    // Assert(verify)
    
// Test5: Successfully Pop a negative int element from the Stack.

extern void pop_negative_int(void);
    
     // Arrange(setup)
    
    // Act(execute)
    
    // Assert(verify)

// Test6: Successfully Push a NULL element to the Stack.

extern void push_null(void);
    
    // Arrange(setup)
    
    // Act(execute)
    
    // Assert(verify)

// Test7: Successfully Pop a NULL element from the Stack.

extern void pop_null(void);
    
    // Arrange(setup)
    
    // Act(execute)
    
    // Assert(verify)

// Test8: Successfully Push multiple large unsigned int elements to the Stack.

extern void push_multiple_unsigned_int(void);
     
    // Arrange(setup)
    
    // Act(execute)
    
    // Assert(verify)

// Test9: Successfully Pop multiple large unsigned int elements from the Stack in reverse order.

extern void pop_multiple_unsigned_int(void);
    
    // Arrange(setup)
    
    // Act(execute)
    
    // Assert(verify)

// Test10: Successfully Push multiple large negative signed int elements to the Stack.

extern void push_multiple_signed_int(void);
    
    // Arrange(setup)
    
    // Act(execute)
    
    // Assert(verify)

// Test11: Successfully Pop multiple large negative signed elements from the Stack in reverse order.

extern void pop_multiple_signed_int(void);
    
    // Arrange(setup)
    
    // Act(execute)
    
    // Assert(verify)

// Test12: Successfully Push a char element to the Stack.

extern void push_char(void);
    
    // Arrange(setup)
    
    // Act(execute)
    
    // Assert(verify)

// Test13: Successfully Pop a char element from the Stack.

extern void pop_char(void);
        
    // Arrange(setup)
    
    // Act(execute)
    
    // Assert(verify)



// Test14: Successfully test the Stack Empty condition.

extern void stack_empty(void);
        
    // Arrange(setup)
    
    // Act(execute)
    
    // Assert(verify)

// Test15: Successfully test the Stack Full condition.

extern void stack_full(void);
        
    // Arrange(setup)
    
    // Act(execute)
    
    // Assert(verify)

// Test16: Successfully test Error condition, when lower bound of the Stack is breached.

extern void stack_lower_bounds(void);
        
    // Arrange(setup)
    
    // Act(execute)
    
    // Assert(verify)

// Test17: Successfully test Error condition when upper bound of the Stack is breached.

extern void stack_upper_bounds(void);
        
    // Arrange(setup)
    
    // Act(execute)
    
    // Assert(verify)

#endif
