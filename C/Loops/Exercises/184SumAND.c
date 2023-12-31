/*
Write a efficient program that receives a number n from the user.
The program should calculate and print the of all number from 1 to n that
can be divided by 3 >> AND << 5.
*/

#include <stdio.h>

int main()
{
    int n, i;
    int sum = 0;

    printf("Enter a int number: ");
    scanf("%d", &n);

    /* My first solution */
    // for (i = 1; i <= n; i++)
    //     {
    //         if (i % 3 == 0 && i % 5 == 0)
    //             {
    //                 sum = sum + i;
    //             }
    //     }

    /* Optmized solution*/

    for (i = 1; i <= n; i = i + 15) // 15 is the Least Common Multiple
        {
            sum = sum + 1;
        }

    printf("%d\n\n", sum);

    return 0;
}
