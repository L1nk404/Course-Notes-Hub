#include <stdio.h>
#include <stdlib.h>

void printMinMax(int number1, int number2)
{
    (number1 > number2) ? printf("Max: %d, Min: %d", number1, number2)
                        : printf("Max: %d, Min: %d", number2, number1);
}

int main()
{
    int i, j;

    printf("Enter two values: ");
    scanf("%d", &i);
    scanf("%d", &j);

    printMinMax(i, j);

    return 0;
}