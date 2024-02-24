/*
Using the past example, last see how to deal when the lenght of the array
changes.
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 7 // Here we define a constant name and its value

int main()
{
    int grade[SIZE]; // array declaration if lenght = SIZE and element type set
                     // to int
    int i;            // It will control the loop
    int lowest_grade; // It will store the lowest grade so far in your loop

    for (i = 0; i < SIZE; i++)
        {
            printf("Enter grade no.%d: ", i + 1);
            scanf("%d",
                  &grade[i]); // Filing the array in the corresponding index i
        }

    lowest_grade = grade[0];

    for (i = 1; i < SIZE; i++)
        {
            if (grade[i] < lowest_grade)
                {
                    lowest_grade = grade[i];
                }
        }

    printf("\nThe lowest grade is %d\n\n", lowest_grade);

    return 0;
}