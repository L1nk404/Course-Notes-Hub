#include <stdio.h>
#include <stdlib.h>

void swap(int a, int b, int *pA, int *pB)
{
    *pA = b;
    *pB = a;
}

int main()
{
    int a = 1, b = 2;

    swap(a, b, &a, &b);

    printf("a = %d, b = %d\n\n", a, b);

    return 0;
}