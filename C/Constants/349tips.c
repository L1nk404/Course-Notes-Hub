/*
[!] Why using constants?
    1. Perfomance
    2. Defense -  protects you to accidentaly change something that are not
                  suposed to.
    2. Code Readability
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    const year = 2000; // the same as const int age = 35

    // A pointer to a constant, value we're pointing CANNOT BE CHANGED, Pointer
    // itself CAN BE CHANGED
    const int *ptr;

    // constant pointer to "int" variable.
    // Value we're pointing to CAN BE CHANGED.
    // Pointer itself CAN'T BE CHANGED.
    int *const ptr;

    // Constant pointer pointing to constant integer
    // Neither the Pointer nor the Value can be changed.
    // BOTH ARE CONSTANTS!
    const int *const ptr;

    return 0;
}