//*****File Name: Structures/Filling_CharArrays.c */

#include <stdio.h>
#include <string.h>
 struct student {
    char name[20];   
    int age;
};
int main ()
{

    char name[20];
    //name = "Muhammad";//This is not possible.
    strcpy(name , "Muhammad");
    
    struct student s1;
    //s1.name= "Mustafa"; //This is not possible.
    printf("Filling char array of struct s1 using strcpy():\n");
    strcpy(s1.name , "Mustafa");
    printf("\tName of student s1: %s\n",  s1.name);
    /*********************/
    printf("Filling char array struct s2 using Initialization:\n");
    struct student s2 = {"Khaled"};
    printf("\tName of student s2: %s\n", s2.name);
    /*********************/
    //s2={"Ammeer", 12};//Not possible
    s2=s1;
    printf("Copy s2 from s1 using Assignment operation :\n");
    printf("\tName of student s2 becomes: %s", s2.name);
    printf("\n");
    return 0;
}
/*
    Ideas:
        - In Structs, if you have elements defined as char arrays, in this case you should be careful in case of filling this array.
        - In general, we cannot assign array using assignment operator like this:
            name = "Muhammad";//This is not possible.
          This is also valid for array as struct element like this:
            s1.name= "Mustafa"// This is not possible.
        - Instead we can:
                Use strcpy: strcpy(s1.name , "Muhammad");
                or 
                At the time of definition: struct student s2 = {"Khaled", 12};
        We cannot reassign already defined struct to a new values like that "s2={"Ameer", 12}; "
        But we can assign already defined struct to an already defined struct : s2=s1;

*/