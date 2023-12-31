/*
Write a efficient program that receives a number n from the user.
The program should calculate and print the of all number from 1 to n that
can be divided by 3 >> OR << 5.
*/

#include <stdio.h>

int main()
{
    int n, i;
    int sum = 0;

    printf("Enter a int number: ");
    scanf("%d", &n);

    /* My first solution */
    // for (i = 1; i <= n; i++) //In this case if n = 100 --> 100 iterations.
    //     {
    //         if (i % 3 == 0 & || i % 5 == 0)
    //             {
    //                 sum = sum + i;
    //             }
    //     }

    /* Optmized solution*/

    for (i = 3; i <= n; i = i + 3) // if n = 100 --> 33 iterations
        sum = sum + i;

    for (i = 5; i <= n; i = i + 5) // if n = 100 --> 20 iterations
        {
            if (i % 3 != 0) // removing duplications.
                sum = sum + i;
        }

    // for n = 100 --> 55 iterations agains 100 iterations in the code above.

    printf("%d\n\n", sum);

    return 0;
}
