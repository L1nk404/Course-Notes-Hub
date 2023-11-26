/*
Write a program that sould calculate the result of num^<pow> and print
the result on the screen.
*/

#include <stdio.h>

int main()
{

    int num, pow, product;
    int tempPow; // Holds the original value of pow

    product = 1;

    printf("Enter a int number and the power that you want to calculate: ");
    scanf("%d %d", &num, &pow);
    tempPow = pow;

    while (pow > 0)
        {
            product = num * product;
            pow--;
        }

    printf("%d^{%d} = %d\n", num, tempPow, product);

    return 0;
}