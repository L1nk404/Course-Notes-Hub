/*
Write a progam that receives an integer - "n".
The program should print a right angle triangle with a
follow pattern up to a given "n"
Example:
    n = 3

    1
    12
    123
*/

#include <stdio.h>

int main()
{
    int i, j; // for control
    int n, k;

    printf("Enter a natural number: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= i; j++)
                {
                    printf("%d ", j);
                }
            printf("\n");
        }

    return 0;
}