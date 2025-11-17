#include <stdio.h>

#define SET_BIT(reg,bit)    (reg |= (1<< bit))    // considering 32 bits register, the first bit is 0 and the last bit is 31
#define RESET_BIT(reg,bit)  (reg &= ~(1<< bit))   // considering 32 bits register, the first bit is 0 and the last bit is 31

int main ()
{
    int numbers[] = {0xffffffff,0x0,0x10,0xffffffef}; //Array contain numbers to be used as an examples.
    int temp;// Temp variable to be used to not affect the original numbers in the arrays.
    for (int i =0 ; i<sizeof(numbers)/sizeof (int );i++)
    
    {
    printf ("%d-The number is 0x%x(in hex).\n ",i+1,numbers[i]);
    temp=SET_BIT(numbers[i],4);
    printf("\tBit 5 is Set ?\t\t0x%x(in hex).\n",temp);
    temp=RESET_BIT(numbers[i],4);
    printf("\tBit 5 is Reset ?\t0x%x(in hex).\n",temp);
    }
    
    return 0;
}