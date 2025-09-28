//*****File Name:Structures/StructPointers.c */
#include <stdio.h>
typedef struct {
    double x;
    double y;
} point;
void printLine()
{
    printf("-----------------------------\n");
}
void demonstrate_StrPointersAssignment()
{

    point point1={0};
    point point2= point1;
    point *point3 = & point1;
    (*point3).x = 1.0;

    printf("point1.x= %f point2.x= %f (*point3).x =%f \n",point1.x,point2.x,(*point3).x);
    point3->x=2.0;// You can use this method.
    //"(*point3).x=2.0;// or you can use this method.
    printf("Change the x value of the pointer point3 to 2.0, this will cause the point1.x to be set to 2.0 as well\n");
    printf("point1.x= %f point2.x= %f point3->x =%f \n",point1.x,point2.x,point3->x);
    printf("\n");
  
}

void demonstrate_StrPointersAddress()
{
    point point1={0};
    point point2= point1;
    point *point3 = & point1;
    printf("Address that the struct pointer (point3) is pointing to is:\t\t%p\n",point3); 
    printf("Address of the first element of the original struct (point1.x):\t\t%p\n",&(point1.x)); 
    printf("The address that the struct pointer is pointing to is the same address of the first element of the struct\n");
    printf("\n");
}

void demonstrate_StrValueChangeViaPointer()
{
    point point1 = {1.0,2.0};
    point point2 = point1;
    point *point3 = &point1;
    point point4 = {5.0,6.0};

    printf("We will change the value of the struct that the pointer (point3) is pointing to: \n");
    printf("\tBefore (point3 = &point1):\tpoint1.x= %f point2.x= %f (*point3).x =%f \n",point1.x,point2.x,(*point3).x);
    *point3 = point4;    
    printf("\tAfter (*point3 = point4):\tpoint1.x= %f point2.x= %f (*point3).x =%f \n",point1.x,point2.x,(*point3).x);
    printf("\t\tThis leads to the original struct (point1) to be changed.\n");
    printf("\n");
    

}
void demonstrate_StrPointerReassignment()
{
    point point1 = {1.0,2.0};
    point point2 = point1;
    point *point3 = &point1;
    point point4 = {5.0,6.0};
    
    printf("We will change the address that the pointer (point3) is pointing to: \n");
    printf("\tBefore (point3 = &point1):\tpoint1.x= %f point2.x= %f (*point3).x =%f \n",point1.x,point2.x,(*point3).x);
    point3 = & point4;
    printf("\tAfter (point3 = & point4):\tpoint1.x= %f point2.x= %f (*point3).x =%f \n",point1.x,point2.x,(*point3).x);
    printf("\t\tThis NOT lead to a change of the original point (point1).\n");
    printf("\n");
    // *point3 = & point4;  //Not possible, Wrong datatype assignement.
    // point3 = point4;     //Not possible, Wrong datatype assignement.
}

int main()
{
    demonstrate_StrPointersAssignment();
    printLine();

    demonstrate_StrPointersAddress();
    printLine();

    demonstrate_StrValueChangeViaPointer();
    printLine();
    
    demonstrate_StrPointerReassignment();
    printLine();
    return 0;
    
}