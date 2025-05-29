/*
Write a program that receive from the user year, month and day
The program should print the date in Hexadecimal format.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int day, month, year;

    printf("Enter a day: ");
    scanf("%d", &day);
    if (0 < day && day <= 31)
        {
            printf("Enter a month: ");
            scanf("%d", &month);

            if (0 < month && month <= 12)
                {
                    printf("Enter a year: ");
                    scanf("%d", &year);
                    printf("%X/%X/%X", day, month, year);
                }
            else
                {
                    printf("Invalid input for month");
                    return 0;
                }
        }
    else
        {
            printf("Invalid input for day");
            return 0;
        };

    return 0;
}