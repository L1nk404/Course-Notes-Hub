/*
Write a program that reads the temperature from user for 7 days and
calculates and print:
- Average Temperature
- Hottest day of the Week
- Coldest day of the Week
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

const char *weekDayName(int n)
{
    /*Transform a int number in [0,6] on a string containg the day of week.*/
    switch (n)
        {
            case 0:
                return "Sunday";
            case 1:
                return "Monday";
            case 2:
                return "Tuesday";
            case 3:
                return "Wednesday";
            case 4:
                return "Thursday";
            case 5:
                return "Friday";
            case 6:
                return "Saturday";
        }
}

double AverageCalc(double data_array[])
{
    int j;
    double sum = 0;

    for (j = 0; j < SIZE; j++)
        {
            sum = sum + data_array[j];
        }

    return sum / SIZE;
}

int main()
{
    double temperature[SIZE];
    double maxTemp, minTemp, averageTemp;
    int hottestDay = 0, coldestDay = 0;
    int i;

    for (i = 0; i < SIZE; i++)
        {
            printf("Enter the %s temperature: ", weekDayName(i));
            scanf("%lf", &temperature[i]);
        }

    averageTemp = AverageCalc(temperature);
    maxTemp = temperature[0];
    minTemp = temperature[0];

    for (i = 1; i < SIZE; i++)
        {
            if (temperature[i] > maxTemp)
                {
                    maxTemp = temperature[i];
                    hottestDay = i;
                }
            else if (temperature[i] < minTemp)
                {
                    minTemp = temperature[i];
                    coldestDay = i;
                }
        }

    printf("\nThe week average temperature is %.2lf.\n", averageTemp);
    printf("The hottest day was %s with a temperature of %.2lf.\n",
           weekDayName(hottestDay), maxTemp);
    printf("The coldest day was %s with a temperature of %.2lf.\n",
           weekDayName(coldestDay), minTemp);

    return 0;
}