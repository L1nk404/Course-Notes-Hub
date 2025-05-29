/*
Print the sum of i=1 until j where j is given by the user.
*/

#include <stdio.h>

int main()
{
    int sum = 0;
    int i, j;

    printf("Enter j value: ");
    scanf("%d", &j);

    for (i = 1; i <= j; i++)
        {
            sum = sum + i;
        }

    printf("The sum value is %d\n\n", sum);

    return 0;
}