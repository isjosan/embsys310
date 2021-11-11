#define SIZE 5
int powers[SIZE];

void func1(int num1, int num2, int num3, int num4, int num5);
void func2(void);

int main(void)
{
    func2();
    
    return 0;
}

void func2(void)
{
    int num1 = 2;
    int num2 = 4;
    int num3 = 8;
    int num4 = 16;
    int num5 = 32;
    
    func1(num1, num2, num3, num4, num5);
}

void func1( int num1, int num2, int num3, int num4, int num5)
{
    powers[0] = num1;
    powers[1] = num2;
    powers[2] = num3;
    powers[3] = num4;
    powers[4] = num5;
}
