#include <stdio.h>

int Set_5thBit(int);
int Reset_5thBit(int );

int main ()
{
    int numbers[] ={0xffffffff,0x0,0x10,0xffffffef}; //Array contain numbers to be used as an examples.
    int temp;// Temp variable to be used to not affect the original numbers in the arrays.
    for (int i =0 ; i<sizeof(numbers)/sizeof (int );i++)
    {
    printf ("%d-The number is 0x%x(in hex).\n ",i+1,numbers[i]);
    temp=Set_5thBit(numbers[i]);
    printf("\tBit 5 is Set ?\t\t0x%x(in hex).\n",temp);
    temp=Reset_5thBit(numbers[i]);
    printf("\tBit 5 is Reset ?\t0x%x(in hex).\n",temp);
    }
    
    return 0;
}

int Set_5thBit (int num){
    int mask =  0x10;   //All mask bits are set to 0s except for 5th bit
    int result = num | mask;    // With | operation between the given number and the mask the bit 5 will be set to 1.
    return result;
}
int Reset_5thBit (int num)
{
    int mask = (int) 0xFFFFFFEF;   //All mask bits are kept 1s except for the 5th bit is set to 0;
    //mask could be also defined mask = ~0x10
    int result = num & mask;    // With & operation between the given number and the mask the bit 5 will be reset to 0.
    return result ;
}