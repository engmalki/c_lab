//*****File Name:Structures\Wrapping_C-Arrays.c*/
#include <stdio.h>
#include <string.h>
typedef struct {
    int array[5]; 
} arrStruct;

void arrayPrint (int inputArray[], int arraySize)
{
    for (int i =0 ; i<arraySize ;i++)
    {
        printf("%d\t ",inputArray[i]);
    }
    printf("\n");
}
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
    arrayPrint (arr1, 5);
    
    //printing arr2 elements before using memcpy ()
    printf("\tarr2\t\t=\t\t");
    arrayPrint (arr2, 5);

    //arr2 = arr1// This is not possible. For C-array we can not assign array directly to another array.
    memcpy (arr2,arr1, sizeof(arr2)); // memcpy can be used to copy block of memory from one location to another and it can be useful for C-array.
    printf("After using memcpy(): \n");
    
    //Adresses of the arrays before using memcopy()
    printf("\tAddress of arr1:\t%p\n", arr1);
    printf("\tAddress of arr2:\t%p\n", arr2);
    
    //re printing arr1 elements for comparison
    printf("\tarr1\t\t=\t\t");
    arrayPrint (arr1, 5);
    
    printf("\tarr2\t\t=\t\t");
    //printing arr2 elements after using memcpy ()
    arrayPrint (arr1, 5);

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
    arrayPrint (arrStruct1.array, 5);
    
    //printing the arrStruct2.array elements before assigenment
    printf("\tarrStruct2.array\t= \t");
    arrayPrint (arrStruct2.array, 5);

    //Assigenment performed to arrStruct2 from arrStruct1
    arrStruct2 = arrStruct1;
    printf("After using Struct assignment: \n");
    printf("\tAddress of arrStruct1:\t%p\n", &arrStruct1);
    printf("\tAddress of arrStruct2:\t%p\n", &arrStruct2);
    //printing the elements After assigenment
    
    printf("\tarrStruct1.array\t= \t");
    arrayPrint (arrStruct1.array, 5);
    
    printf("\tarrStruct2.array\t= \t");
    arrayPrint (arrStruct2.array, 5);
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