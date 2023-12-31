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
    int n; // user input variable
    int i = 1, j = 1;
    int k = 1, l = 0;

    /*
    Loop control:
    i: Is the main row while loop.
    j: Is the value to be printed in each column.
    k: control blank spaces loop.
    l: control control the quantity of values to be printed for each row.
    */

    printf("Enter a integer number n: ");
    scanf("%d", &n);

    while (i <= n) // roll loop
        {
            for (k = 1; k <= (n - i); k++) // Printing blank spaces
                {
                    printf(" ");
                }

            for (l = 1; l <= i; l++)
                {
                    if (j == 10)
                        {
                            j = 0; // resets j value.
                        }

                    printf("%d ", j);

                    j++;
                }

            i++;
            printf("\n");
        }

    return 0;
}
