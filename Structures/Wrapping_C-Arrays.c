//*****File Name:Structures\Wrapping_C-Arrays.c*/
#include <stdio.h>
#include <string.h>
typedef struct {
    int array[5]; 
} arrStruct;

int main()
{
    
// 🔹 Section 1: Copying C arrays using memcpy

    //Creating two arrays
    int arr1[5] = {1,3,5,7,9};
    int arr2[5];
    printf("Before using memcpy(): \n");
    //Adresses of the arrays before using memcopy()
    printf("\tAddress of arr1:\t%p\n", arr1);
    printf("\tAddress of arr2:\t%p\n", arr2);

    //printing arr1 elements
    printf("\tarr1\t\t=\t\t");
    for (int i =0 ; i<5 ;i++)
    {
        printf("%d\t ",arr1[i]);
    }
    printf("\n");
    
    //printing arr2 elements before using memcpy ()
    printf("\tarr2\t\t=\t\t");
    for (int i =0 ; i<5 ;i++)
    {
        printf("%d\t ",arr2[i]);
    }
    printf("\n");

    //arr2 = arr1// This is not possible. For C-array we can not assign array directly to another array.
    memcpy (arr2,arr1, sizeof(arr2)); // memcpy can be used to copy block of memory from one location to another and it can be useful for C-array.
    printf("After using memcpy(): \n");
    
    //Adresses of the arrays before using memcopy()
    printf("\tAddress of arr1:\t%p\n", arr1);
    printf("\tAddress of arr2:\t%p\n", arr2);
    
    //re printing arr1 elements for comparison
    printf("\tarr1\t\t=\t\t");
    for (int i =0 ; i<5 ;i++)
    {
        printf("%d\t ",arr1[i]);
    }
    printf("\n");
    
    printf("\tarr2\t\t=\t\t");
    //printing arr2 elements after using memcpy ()
    for (int i =0 ; i<5 ;i++)
    {
        printf("%d\t ",arr2[i]);
    }
    printf("\n");  
    printf("Result: With \"memcopy()\" values are only copied and addresses did not change.\n");
    printf("-----------------------------------------------------\n");
/*****************/
    
// 🔹 Section 2: Copying structs containing arrays

    //Createing two structs of arrStruct
    arrStruct arrStruct1 ;
    arrStruct arrStruct2 ;
    printf("Before using Struct assignment: \n");
    //Adresses of the arrays before using memcopy()
    printf("\tAddress of arrStruct1:\t%p\n", &arrStruct1);
    printf("\tAddress of arrStruct2:\t%p\n", &arrStruct2);
    //Filling the first arrStruct1
    for (int i =0 ; i<5 ;i++)
    {
        arrStruct1.array[i]=i;    
    }
    
    //printing the arrStruct1.array elements 
    printf("\tarrStruct1.array\t= \t");
    for (int i =0; i<5; i++)
        {
            printf("%d\t ",arrStruct1.array[i]);
        }
    printf("\n");
    
    //printing the arrStruct2.array elements before assigenment
    printf("\tarrStruct2.array\t= \t");
    for (int i =0; i<5; i++)
        {
            printf("%d\t ",arrStruct2.array[i]);
        }
    printf("\n");
    
    //Assigenment performed to arrStruct2 from arrStruct1
    arrStruct2 = arrStruct1;
    printf("After using Struct assignment: \n");
    printf("\tAddress of arrStruct1:\t%p\n", &arrStruct1);
    printf("\tAddress of arrStruct2:\t%p\n", &arrStruct2);
    //printing the arrStruct2.array elements After assigenment
    printf("\tarrStruct2.array\t= \t");
    for (int i =0; i<5; i++)
        {
            printf("%d\t ",arrStruct2.array[i]);
        }

    printf("\n");
    printf("-----------------------------------------------------\n");
/*****************/
    
// 🔹 Section 3: Comparing memory sizes of arrays vs structs
    //Show the size of the array and the struct with array with the same number of elements.
    printf("The size of struct contains an array of 5 integers elements is: %lu\n",sizeof (arrStruct1) );
    printf("The size of array of 5 integer elements is: %lu\n",sizeof (arr1) );
    printf("\tBoth are the same size.");
    printf("\n");
    printf("-----------------------------------------------------\n");
    /*****************/
    printf("Program finished.\n");
    return 0;
        

}