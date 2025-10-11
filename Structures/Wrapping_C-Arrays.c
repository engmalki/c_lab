//*****File Name:Structures\Wrapping_C-Arrays.c*/
#include <stdio.h>
#include <string.h>
#define ARRAY_SIZE 5
typedef struct {
    int array[ARRAY_SIZE]; 
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
    int arr1[ARRAY_SIZE] = {1,3,5,7,9};
    int arr2[ARRAY_SIZE];
    printf("Before using memcpy(): \n");
    //Adresses of the arrays before using memcopy()
    printf("\tAddress of arr1:\t%p\n", arr1);
    printf("\tAddress of arr2:\t%p\n", arr2);

    //printing arr1 elements
    printf("\tarr1\t\t=\t\t");
    arrayPrint (arr1, ARRAY_SIZE);
    
    //printing arr2 elements before using memcpy ()
    printf("\tarr2\t\t=\t\t");
    arrayPrint (arr2, ARRAY_SIZE);

    //arr2 = arr1// This is not possible. For C-array we can not assign array directly to another array.
    memcpy (arr2,arr1, sizeof(arr2)); // memcpy can be used to copy block of memory from one location to another and it can be useful for C-array.
    printf("After using memcpy(): \n");
    
    //Adresses of the arrays before using memcopy()
    printf("\tAddress of arr1:\t%p\n", arr1);
    printf("\tAddress of arr2:\t%p\n", arr2);
    
    //re printing arr1 elements for comparison
    printf("\tarr1\t\t=\t\t");
    arrayPrint (arr1, ARRAY_SIZE);
    
    printf("\tarr2\t\t=\t\t");
    //printing arr2 elements after using memcpy ()
    arrayPrint (arr1, ARRAY_SIZE);

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
    for (int i =0 ; i<ARRAY_SIZE ;i++)
    {
        arrStruct1.array[i]=i+1;    
    }
    
    //printing the arrStruct1.array elements 
    printf("\tarrStruct1.array\t= \t");
    arrayPrint (arrStruct1.array, ARRAY_SIZE);
    
    //printing the arrStruct2.array elements before assigenment
    printf("\tarrStruct2.array\t= \t");
    arrayPrint (arrStruct2.array, ARRAY_SIZE);

    //Assigenment performed to arrStruct2 from arrStruct1
    arrStruct2 = arrStruct1;
    printf("After using Struct assignment: \n");
    printf("\tAddress of arrStruct1:\t%p\n", &arrStruct1);
    printf("\tAddress of arrStruct2:\t%p\n", &arrStruct2);
    //printing the elements After assigenment
    
    printf("\tarrStruct1.array\t= \t");
    arrayPrint (arrStruct1.array, ARRAY_SIZE);
    
    printf("\tarrStruct2.array\t= \t");
    arrayPrint (arrStruct2.array, ARRAY_SIZE);
    printf("-----------------------------------------------------\n");
/*****************/
    
// 🔹 Section 3: Comparing memory sizes of arrays vs structs
    //Show the size of the array and the struct with array with the same number of elements.
    printf("The size of struct contains an array of %d integers elements is: %lu bytes\n",ARRAY_SIZE,sizeof (arrStruct1) );
    printf("The size of array of %d integer elements is: %lu bytes\n",ARRAY_SIZE,sizeof (arr1) );
    printf("\tBoth are the same size.");
    printf("\n");
    printf("-----------------------------------------------------\n");
    /*****************/
    printf("Program finished.\n");
    return 0;
        

}