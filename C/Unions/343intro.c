/* ============================================================================
>> Unions

[!] Whats is Union?
    1. User-Defined Datatype
    2. A collection of elements (or variables) that are kind of being held in
       the same region of the memory.
    3. Union allocate a space on memory equal to the greatest variable space
       requirement. You can store just one of the variables contained in the
       union.

[!] Union vs Struct
    - Struct: Can be understand as a block of memory which stores elements
              and fields THAT DO NOT overlap each other.
    - Union: Is also a block of memory, but stores several fields in just one
             place, so you can only store ONE of the data fields at time.

[!] Why use union?
    While you can only use one member of a union at a time, this shared
    memory approach can be highly efficient in certain situations,
    especially when you're working with limited memory or need to handle
    different data types in a single memory location.
============================================================================ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union
{
    char firstName[20];
    int age;
} info;

int main()
{
    info myVariable1;

    printf("Size of myVariable1 = %d bytes\n", sizeof(myVariable1));

    myVariable1.age = 30;
    printf("Myvariable1.age = %d\n", myVariable1.age);

    // Copying this string in the myVariable1.firstname region of memory
    strcpy(myVariable1.firstName, "Hello");

    printf("Myvariable1.firstName = %s\n", myVariable1.firstName);
    // Now you can see that myVariale.age was overwrited
    printf("Myvariable1.age as INT = %d\n", myVariable1.age);
    printf("Myvariable1.age as CHAR = %c\n", myVariable1.age);

    return 0;
}