/*
Print a program that reveices as input two values:
    1. number;
    2. pow.

The program should calculte the result of num^{pow}.
(Using For loops)
*/

#include <stdio.h>

int main()
{
    double number, product = 1;
    int pow, i;

    printf("Enter a number: ");
    scanf("%lf", &number);
    printf("Enter the power: ");
    scanf("%d", &pow);

    for (i = 1; i <= pow; i++)
        {
            product = product * number;
        }

    printf("%2.lf", product);

    return 0;
}