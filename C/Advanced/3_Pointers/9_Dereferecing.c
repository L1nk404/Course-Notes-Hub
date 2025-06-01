#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    int *p; // Creating a pointer

    p = &a; // P points to a
    *p = 5; // set the value in the "a" address

    return 0;
}