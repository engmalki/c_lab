//*****File Name: Structures/Structs_Copy_with_Pointers_Elements_2.c */
#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
    int *elements;
    size_t size;
} IntArray;

/* Prototypes */
IntArray DeepCopy (const IntArray *);
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
    if (!arrayA.elements || !arrayB.elements) 
    {
        fprintf(stderr, "Memory allocation failed.\n");
        return EXIT_FAILURE;
    }
/*****************/
// Part1: Compare the addresses of the structs and the addresses of the elements for allocated arrays (arrayA and arrayB) and check if they are the same BEFORE the deep copy:
    printf("Part1: Compare the addresses of the structs and the addresses of the elements for allocated arrays (arrayA and arrayB) and check if they are the same BEFORE the deep copy:\n");
    ArrayAddressesCompare(&arrayA,&arrayB);
    ArrayAddressesElementsCompare(&arrayA,&arrayB);
    PartEnd ();
    printf("\n");
/*****************/

/*****************/
// Part2: Fill the first array and print the values for both arrays arrayA and arrayB BEFORE deep copy.
    printf("Part2: Fill the first array and print the values for both arrays arrayA and arrayB BEFORE deep copy.\n");
    for (size_t i =0; i <arrayA.size; i++)
    {
        arrayA.elements[i] = 10*(i+1);
    }
    
    // Print both arrays to show independence
    printf("\tArrayA elements:");
    for (size_t i = 0; i < arrayA.size; i++)
        printf("\t%d", arrayA.elements[i]);
    printf("\n");

    printf("\tArrayB elements:");
    for (size_t i = 0; i < arrayB.size; i++)
        printf("\t%d", arrayB.elements[i]);
    printf("\n");
    
    PartEnd();
    printf("\n");
/*****************/

/*****************/
//Part3: Perform Deep Copy and Print the values for both arrays arrayA and arrayB AFTER deep copy.
printf("Part3: Perform Deep Copy and Print the values for both arrays arrayA and arrayB AFTER deep copy.\n");
    //free the already allocated memory for arrayB to avoid memory leak as the deep copy function is already allocate new memory.
    free(arrayB.elements); 
    // Perform deep copy
    arrayB = DeepCopy(&arrayA);
    printf ("Deep Copy is performed between the two Structs \"arrayB = DeepCopy(arrayA)\".\n\n");
    
    // Print both arrays
    printf("After DeepCopy:\n");
    printf("\tArrayA elements:");
    for (size_t i = 0; i < arrayA.size; i++)
        printf("\t%d", arrayA.elements[i]);
    printf("\n");

    printf("\tArrayB elements:");
    for (size_t i = 0; i < arrayB.size; i++)
        printf("\t%d", arrayB.elements[i]);
    printf("\n");
    PartEnd();
    printf("\n");
/*****************/

/*****************/   
//Part4: Compare the addresses of the structs and the addresses of the elements for allocated arrays (arrayA and arrayB) and check if they are the same AFTER deep copy.
    printf("Part4: Compare the addresses of the structs and the addresses of the elements for allocated arrays (arrayA and arrayB) and check if they are the same AFTER deep copy:\n");
    ArrayAddressesCompare(&arrayA,&arrayB);
    ArrayAddressesElementsCompare(&arrayA,&arrayB);
    PartEnd();
    printf("\n");
    
/*****************/

/*****************/
//Part5: Fill the first struct arrayA.elements again with sample values and print arrays elements values of structs arrayA and arrayB.
    printf("Part5: Fill the first struct arrayA.elements again with sample values and print arrays elements values of structs arrayA and arrayB.\n");
    int sampleValue []={1,14,8,6,9,8};
    //"size_t" is used to match the size type of the struct element "size"
    for (size_t i=0;i<arrayA.size; i++)
        arrayA.elements[i] = sampleValue[i];

    // Print both arrays
    printf("\tArrayA elements:");
    for (size_t i = 0; i < arrayA.size; i++)
        printf("\t%d", arrayA.elements[i]);
    printf("\n");

    printf("\tArrayB elements:");
    for (size_t i = 0; i < arrayB.size; i++)
        printf("\t%d", arrayB.elements[i]);
    printf("\n");
    PartEnd ();
    printf("\n");
/*****************/

/*****************/
//Part6: Free allocated memory.
    free(arrayA.elements);
    free(arrayB.elements);
    arrayA.elements = NULL;
    arrayB.elements = NULL;
    return 0;
}

// Deep copy function: allocates new memory and copies contents
IntArray DeepCopy(const IntArray *src) {
    IntArray dest;
    dest.size = src->size;
    dest.elements = malloc(sizeof(int) * dest.size);
    if (!dest.elements) {
        fprintf(stderr, "Memory allocation failed in DeepCopy.\n");
        exit(EXIT_FAILURE);
    }
    
    for (size_t i = 0; i < dest.size; i++) {
        dest.elements[i] = src->elements[i];
    }
    return dest;
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