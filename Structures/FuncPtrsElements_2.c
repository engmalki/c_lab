
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
    MathOp Ops[NUMBEROFELEMENTS] = {
        {.x=1,        .y=2,        .op = Sum},
        {.x=1,        .y=2,        .op = Sub},
        {.x=1,        .y=2,        .op = Muliplication}
       
    };
    int result = 0;
    for (int i=0; i< NUMBEROFELEMENTS; i++)
    {
        result = Ops[i].op (Ops[i].x , Ops[i].y);
        printf ("The result %d= %d\n", i+1, result);
    }


    return 0;
}
