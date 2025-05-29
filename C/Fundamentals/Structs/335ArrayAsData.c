// Structs having arrays as data members and copying struct variables
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[10];
    float age;
    int id;
} Employee;

int main()
{
    Employee emp1;
    Employee emp2 = {"Jake", 24.5, 123};

    /*
    Using the "=" to copy value-by-value (the member of one struct vartiable to
    another of the same type).
    >> note: copying static arrays in assignment between two structs variable is
    a little bit different than "simply" copying an array (element by element).
    */
    emp1 = emp2;

    printf("Employee #1 name is %s\n", emp1.name);
    printf("Employee #2 name is %s\n", emp2.name);

    // Making sure that these are a full copies (and not just referring to the
    // same place)
    strcpy(emp1.name, "Jhon");
    emp1.id = 456;

    printf("Employee #1 name is %s\n", emp1.name);
    printf("Employee #2 name is %s\n", emp2.name);
    printf("Employee #1 id is %d\n", emp1.id);
    printf("Employee #2 id is %d\n", emp2.id);

    return 0;
}