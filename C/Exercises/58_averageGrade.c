#include <stdio.h>
#include <stdlib.h>

int main(){
    int grade1, grade2, grade3;
    double average_grade;

    printf("Type your 1st grade: ");
    scanf("%d", &grade1);
    printf("Type your 2nd grade: ");
    scanf("%d", &grade2);
    printf("Type your 3rd grade: ");
    scanf("%d", &grade3);

    average_grade = ((double)grade1 + grade2 + grade3)/3;

    printf("\nYour average grade is %.2lf", average_grade);

    return 0;
}