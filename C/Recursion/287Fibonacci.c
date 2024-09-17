/*
Write a recursive Fibonacci function that:
1. Reveices a "n" (Index)
2. return the value at index "n"

Fibonnaci is defined as

Fn := { 0, if n = 0 ,
        1, if n = 1
        F_{n-1} + F_{n-2}, if n > 1
*/

#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n)
{
    int Fn;

    if (n == 0)
        {
            return 0;
        }
    if (n == 1)
        {
            return 1;
        }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    int result;

    printf("Enter a integer n: ");
    scanf("%d", &n);

    result = fibonacci(n);

    printf("The Fn value is: %d\n\n", result);

    return 0;
}