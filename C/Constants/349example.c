#include <stdio.h>
#include <stdlib.h>

int main()
{
    int age1 = 27;
    int age2 = 21;

    // Creating constant pointer that point to variable "age"
    int *const ptr = &age1;
    *ptr = 30;

    // // This attempt to change the pointer itself will triger an error
    // ptr = &age2;

    return 0;
}