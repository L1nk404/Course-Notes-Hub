#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 5;

    int *ptr1 = &a;     // pointer to int
    int **ptr2 = &ptr1; // pointer to a pointer to int

    return 0;
}