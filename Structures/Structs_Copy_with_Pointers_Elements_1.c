//*****File Name: Structures/Structs_Copy_with_Pointers_Elements_1.c */
#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
    int *elements;
    size_t size;
} IntArray;

/* Prototypes */
void ArrayAddressesElementsCompare(const IntArray *, const IntArray *);
void ArrayAddressesCompare(const IntArray* , const IntArray *);
void PartEnd ();
/* EndOfPrototypes */

int main ()
{
    IntArray arrayA;
    IntArray arrayB;
    arrayA.size=6;
    arrayB.size=6;
    arrayA.elements = malloc (sizeof (int )*arrayA.size);
    arrayB.elements = malloc (sizeof (int )*arrayB.size);
    /*
    if (arrayA.elements==NULL || arrayB.elements== NULL)
    {
        printf("Dynamic memory allocation failed. Exiting the program.\n");
        return 1;
    }
    */  
    if (!arrayA.elements || !arrayB.elements) 
    {
        fprintf(stderr, "Memory allocation failed.\n");
        return EXIT_FAILURE;
        /* The previous commented code is functional but the following improvements are made: 
            "!pointer" is the idiomatic way to check for NULL in C.
            fprintf(stderr, …) makes it explicit that this is an error message.
            EXIT_FAILURE (from <stdlib.h>) is more portable than returning 1, for eaxmple, on OpenVMS, exit(1) indicates success.
        */
    }
/*****************/
// Part1: Compare the addresses of the structs and the addresses of the elements for allocated arrays arrayA and arrayB and check if they are the same BEFORE the assignment (Shallow Copy):
    printf("Part1: Compare the addresses of the structs and the addresses of the elements for allocated arrays arrayA and arrayB and check if they are the same BEFORE the assignment (Shallow Copy):\n");
    ArrayAddressesCompare(&arrayA,&arrayB);
    ArrayAddressesElementsCompare(&arrayA,&arrayB);
    PartEnd ();
    printf("\n");
/*****************/

/*****************/
//Part2: Compare the addresses of the structs and the addresses of the elements for allocated arrays arrayA and arrayB and check if they are the same AFTER the assignment (Shallow Copy)
    printf("Part2: Compare the addresses of the structs and the addresses of the elements for allocated arrays arrayA and arrayB and check if they are the same AFTER the assignment (Shallow Copy):\n");
    //Assignment operation (Shallow Copy) is performed between the strctus
    free(arrayB.elements); // IMPORTANT: Free the previously allocated memory for arrayB.elements to avoid memory leak before shallow copy
    arrayB=arrayA;
    printf ("ASSIGNMENT operation (Shallow Copy) performed between the two Structs \"arrayB = arrayA\".\n\n");
    
    ArrayAddressesCompare(&arrayA,&arrayB);
    ArrayAddressesElementsCompare(&arrayA,&arrayB);
    PartEnd ();
    printf("\n");
/*****************/

/*****************/
//Part3: Fill the first struct arrayA.elements only and check both arrays of structs arrayA and arrayB.
    printf("Part3: Fill the first struct arrayA.elements only and check both arrays of structs arrayA and arrayB.\n");
    int sampleValue []={1,14,8,6,9,8};
    //"size_t" is used to match the size type of the struct element "size"
    for (size_t i=0;i<arrayA.size; i++)
        arrayA.elements[i] = sampleValue[i];
        
    //Printing the first struct array elements:
    printf ("\tFirst struct elements:");
    for (size_t i=0;i<arrayA.size; i ++)
        printf("\t%d",arrayA.elements[i]);
    printf("\n");
    
    //Printing the second struct array elements, to show that the struct arrayB.elements is the same for the arrayA.elements.
    printf ("\tSecond struct elements:");
    for (size_t i=0;i<arrayB.size; i ++)
        printf("\t%d",arrayB.elements[i]);
    printf("\n");
    PartEnd ();
    printf("\n");
/*****************/

/*****************/
//Part4: Printing the size of the struct when it has a pointer element and this pointer is dynamically allocated.
    printf ("Part4: Printing the size of the struct when it has a pointer element and this pointer is dynamically allocated.\n");
    printf("\tSize of Struct: %lu",sizeof(arrayA));
    printf("\n");
    PartEnd ();
/*****************/

/*****************/
//Part5: Free allocated memory and set the pointers to NULL and final check if they are 
    printf("Part5: Free allocated memory and set the pointers to NULL and final check if they are successfully set to null \n");
    free(arrayA.elements);
    // Do NOT free arrayB.elements after assignment (Shallow Copy), because it points to the same memory as arrayA.elements.
    arrayA.elements = NULL;
    arrayB.elements = NULL;

    //Check if the ptr is set to NULL. 
    if (arrayA.elements == NULL && arrayB.elements == NULL)
    {
        printf("Memory is free \n");
    }
    else 
    {
        printf ("Memory is not free \n");
    }

/*****************/
    return 0;
}

// To avoid copies the whole struct each time with passing structs by value, passing by "const pointer" is more efficient and conventional
void ArrayAddressesElementsCompare(const IntArray *array1, const IntArray *array2)
{
    printf("\t-----------------------------------------------------\n");
    printf("\tarray1.elements\t\tarray2.elements\t\tCheck Result\n");
    printf("\t-----------------------------------------------------\n");
    for (size_t i=0;i<array2->size; i ++) {
        printf("\t%p\t\t%p\t\t",&array1->elements[i],&array2->elements[i]);
        if (&array1->elements[i]==&array2->elements[i])
            printf("The two addresses are the same.\n");
        else
            printf("The two addresses are different.\n");
    }
}
void ArrayAddressesCompare(const IntArray *array1,const IntArray *array2)
{
    printf("\t-------------------------------------------------------------------------------\n");
    printf("\tAddress of first struct\t\tAddress of second struct\tCheck Result \n");
    printf("\t-------------------------------------------------------------------------------\n");
    printf("\t%p\t\t\t%p",&array1,&array2);
    if (&array1==&array2)
        printf("\t\t\tThe two structs addresses are the same.\n");
    else
        printf("\t\t\tThe two structs addresses are different.\n");
    printf("\t-------------------------------------------------------------------------------\n");
}

void PartEnd ()
{
    printf("============================================================\n");
}