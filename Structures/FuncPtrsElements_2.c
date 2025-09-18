
#include <stdio.h>
# define NUMBEROFELEMENTS 3
typedef struct 
{
    int x;
    int y;
    int (*op)(int, int);
}MathOp;
int Sum (int x, int y)
{
    return x+y;
}
int Sub (int x, int y)
{
    return x-y;
}
int Muliplication (int x, int y)
{
    return x*y;
}

int main ()
{
    MathOp  Op;
    printf("Enter the first number: ");
    scanf("%d",&Op.x);
    printf("Enter the second number:");
    scanf("%d",&Op.y);    
    int opChar;
    printf("Enter operation:\n1. Sum\n2. Substraction\n3. Multiplication\n4.quite\n");
    scanf("%d",&opChar);
    if (opChar == 1)
    {
        Op.op = Sum;
    }
    else if (opChar == 2)
    {        
        Op.op = Sub;
    }   
    else if (opChar == 3)
    {
        Op.op = Muliplication;
    }       
    else if (opChar == 4)
    {
        printf ("\nProgram finished\n");
        return 0;
    }
    else 
    {
        printf ("\nSum is selected as default\n");
        Op.op = Sum;

    }
    
    int result= Op.op(Op.x, Op.y);    
    printf ("The result = %d\n", result);
    return 0;
}
