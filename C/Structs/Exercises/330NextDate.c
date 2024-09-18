/*
Write a program that

1. Receives a date (dd/mm/yyyy) from the user
2. Returns the next day (Take frebruary as 28 days)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Date
{
    int day;
    int month;
    int year;
} Date;

Date inputDate()
{
    Date dt;
    printf("Enter a day (1-31): ");
    scanf("%d", &dt.day);
    if (dt.day < 1 || dt.day > 31)
        {
            printf("Invalid output!\n");
            exit(1);
        }
    printf("Enter a month (1-12): ");
    scanf("%d", &dt.month);
    if (dt.month < 1 || dt.month > 12)
        {
            printf("Invalid output!\n");
            exit(1);
        }
    printf("Enter a year (yyyy): ");
    scanf("%d", &dt.year);
    if (dt.year < 1)
        {
            printf("Invalid output!\n");
            exit(1);
        }

    return dt;
}

void printDate(Date dt) { printf("\n%d/%d/%d\n", dt.day, dt.month, dt.year); }

Date nextDay(Date dt)
{
    // 28 days: 2 (Frebruary)
    // 30 days: 4, 6, 9, 11 (April, June, September, November)
    // 31 days: 1, 3, 5, 7, 8, 10, 12 (January, March, May, July,
    // August, October, December)

    if (dt.day == 28 || dt.month == 2) // frebuary case
        {
            dt.day = 1;
            dt.month++;
            return dt;
        }

    else if (dt.day == 30) // 30 days case
        {
            if ((dt.month < 7 && (dt.month % 2) == 0) ||
                (dt.month > 7 && (dt.month % 2) != 0))
                {
                    dt.day = 1;
                    dt.month++;
                    return dt;
                }
        }
    else if (dt.day == 31) // 31 day case
        {
            if ((dt.month <= 7 && (dt.month % 2) != 0) ||
                (dt.month > 7 && (dt.month % 2) == 0))
                {

                    if (dt.month == 12) // New year
                        {
                            dt.day = 1;
                            dt.month = 1;
                            dt.year++;

                            printf("\n>> Happy New Year !! <<");
                        }
                    else
                        {
                            dt.day++;
                            dt.month++;
                        }
                }
            return dt;
        }

    dt.day++;
    return dt;
}

int main()
{
    Date dt, tomorrow;

    dt = inputDate();

    tomorrow = nextDay(dt);

    printDate(tomorrow);

    return 0;
}