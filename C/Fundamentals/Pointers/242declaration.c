#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Step 1: Declaration

    // P is a pointer variable (not a "standard variable").
    // P will hold a address where resides an int variable.
    int *P; // To declare a pointer we use <data_type>*<pointer_name>

    // Step 2: Usage

    int a = 5; // We initializate a int standard variable called a

    printf("The memory address of 'a' is %p\n\n", &a);
    // Lets print the memory address of "a"  using %p
    // Note that we are not using P yet

    // Now let's address the P pointer to a:
    P = &a;

    printf("Now, using the pointer P we can print P that is the  memory "
           "address of 'a': "
           "%p\n\n",
           P);
    // Note that the P memory address is the same of "a"

    printf("We can also access the value of 'a' using *P: %d\n\n", *P);
    // Here we access the value of 'a' indirectly using *P

    return 0;
}