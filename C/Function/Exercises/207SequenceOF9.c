#include <stdio.h>
#include <stdlib.h>

// Funtion receives some number - "lenght"
// Calculate and return a number if the same lenght of digits 9.

int print9() { printf("9"); } // Another solution

// int GenerateSequenceOf9(int n)
// {
//     int j;
//     int num = 0;

//     for (j = 0; j < n; j++)
//         {
//             num = num * 10 + 9;
//         }

//     return num;
// }

int main()
{
    int n;
    int i;

    printf("Enter a int number: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
        {
            print9(n);
        }

    printf("\n\n");

    return 0;
}