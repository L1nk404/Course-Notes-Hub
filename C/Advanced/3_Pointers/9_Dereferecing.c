#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a; // variável do tipo primitivo inteiro.
    int *p; // Creating a pointer

    p = &a; // P points to a
    *p = 5; // set the value in the "a" address

    printf("%d\n", a);

    return 0;
}