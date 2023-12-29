/*
Write a program that receives an integer "n".
The program should print a print a a pyramid of numbers
with the following pattern:

n = 4:

n
1     1
2    2 3
3   4 5 6
4  7 8 9 0

*/

#include <stdio.h>

int main()
{
    int n;                   // user input var
    int i = 1, j = 1, k = 1; // loop control parameters

    printf("Enter a integer number n: ");
    scanf("%d", &n);

    while (i <= n)
        {
            while (k < n) // Printing blank spaces
                {
                    printf(" "); // funciona com J, mas porque?
                }

            for (j = 1; j <= i; j++)
                {
                    if (j >= 10)
                        {
                            printf("%d", j - 10);
                        }
                    else
                        {
                            printf("%d ", j);
                        }
                }

            k++;
            i++;
            printf("\n");
        }

    return 0;
}
