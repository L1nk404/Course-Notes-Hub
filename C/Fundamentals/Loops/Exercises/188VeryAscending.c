/*
Write a program that receives a number n, than ask for the user to input
a number n times.
If the sequence of numbers is ascending, print "Very ascending"
*/

#include <stdio.h>

int main()
{
    int n, count = 0;
    int CurrentValue, PreviousValue;
    int flag = 1;

    printf("Enter the size of a sequence: ");
    scanf("%d", &n);
    printf("\nEnter a int number: \n");
    scanf("%d", &CurrentValue);
    PreviousValue = CurrentValue - 1;

    do
        {
            printf("Enter a int number: \n");
            scanf("%d", &CurrentValue);
            if (PreviousValue >= CurrentValue)
                {
                    flag = 0;
                }

            CurrentValue = PreviousValue;

            count++;
        }
    while (count < (n - 1));

    if (flag == 1)
        printf("\n\n>>>Very ascending<<<\n\n");
    else
        printf("\n\n>>>Not Ascending<<<\n\n");

    return 0;
}