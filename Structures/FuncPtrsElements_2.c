
#include <stdio.h>
typedef struct 
{
    int x;
    int y;
    int (*op)(int, int);
}MathOp;
int sum (int x, int y)
{
    return x+y;
}
int sub (int x, int y)
{
    return x-y;
}
int Muliplication (int x, int y)
{
    return x*y;
}

int main ()
{
    MathOp SumOp = {
        .x=1,
        .y=2,
        .op = sum
    };
    int result = SumOp.op (SumOp.x,SumOp.y);
    printf ("The result=%d\n", result);
    return 0;
}
