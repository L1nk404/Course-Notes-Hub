/*
1. Receive a number.
2. Calculate its factorial.
3. Return the result.
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
{
    int product = 1;
    int i;

    for (i = 1; i <= n; i++)
        {
            product = product * i;
        }

    return product;
}

int main()
{
    int n;

    printf("Enter a int number: ");
    scanf("%d", &n);

    printf("\nThe factorial of %d is %d.\n\n", n, factorial(n));

    return 0;
}