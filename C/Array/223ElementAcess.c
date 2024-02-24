/*
For that example of usage of array we are create a program that finds the lowest
grade in a array.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int grade[5]; // array declaration if lenght = 5 and element type set to int
    int i;        // It will control the loop
    int lowest_grade; // It will store the lowest grade so far in your loop

    for (i = 0; i < 5; i++)
        {
            printf("Enter grade no.%d: ", i + 1);
            scanf("%d",
                  &grade[i]); // Filing the array in the corresponding index i
        }

    lowest_grade = grade[0];

    for (i = 1; i < 5; i++)
        {
            if (grade[i] < lowest_grade)
                {
                    lowest_grade = grade[i];
                }
        }

    printf("\nThe lowest grade is %d\n\n", lowest_grade);

    return 0;
}