/*
Write a progam that receives as input a grade between 0 and 100.
Then Prints the corresponding value with the grade itself.
*/

#include <stdio.h>

int main()
{
    int grade;

    do
        {
            printf("Enter a grade between 0 to 100: ");
            scanf("%d", &grade);
            printf("Your grade is %d\n", grade);
        }
    while (grade >= 0 && grade <= 100);

    printf("You entered a illegal grade.");

    return 0;
}