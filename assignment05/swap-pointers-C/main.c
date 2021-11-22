// The swap_pointer() function swaps the pointers for int variables x & y.
void swap_pointer(int** arg1, int** arg2);

int main(void)
{  
    int x = 2000000;
    int y = 1000000;
    
    int* xPtr;
    xPtr = &x;
    int* yPtr;
    yPtr = &y;

    int** PtrxPtr;
    int** PtryPtr;
    PtrxPtr = &xPtr;
    PtryPtr = &yPtr;
    
    swap_pointer(PtrxPtr, PtryPtr);
    
    return 0;
}

void swap_pointer(int** arg1, int** arg2)
{   
    int* temp;
    
    temp = *arg2;
    *arg2 = *arg1;
    *arg1 = temp;
}
    
