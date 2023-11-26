/*
Write a program that receives grades from the user until the stop
contition (grade = -1).
The program should calculate the average grade and print it.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    double grade, average_grade, sum = 0, count = 0;

    while (grade != -1)
        {
            count++;
            printf("Enter your grade and [-1] to calculate: ");
            scanf("%lf", &grade);

            if (grade != -1)
                {
                    sum = sum + grade;
                    average_grade = (sum / count); // Count always > 0
                }
        }

    printf("The average grade is %lf\n", average_grade);
    return 0;
}
