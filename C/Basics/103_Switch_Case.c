/*
    swtich cases is a control mecanism that allow us to compare a given
    variable with a multiple cases.
    This Values ALWAYS have to be descrete ( a single value, not a range)
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int a, b, c;
    char grade;

    printf("Enter your grade (A-F): ");
    scanf("%c", &grade);

    switch (grade) // Specifying value
    {
        case 'A': // grade == 'A'
            printf("Grade between 90-100");
            break;

        case 'B': // grade == 'B'
            printf("Grade between 80-89");
            break;

        case 'C': // grade == 'C'
            printf("Grade between 70-79");
            break;

        case 'D': // grade == 'D'
            printf("Grade between 60-69");
            break;

        default:
            printf("FAILED.. Try again");
    }

    return 0;
}