// Write a program that calculates the month salary of a employee

#include <stdio.h>
#include <stdlib.h>

int main(){

    float salary_per_hour, hours_worked;

    printf("How much you receive per hour? ");
    scanf("%f", &salary_per_hour);
    printf("How many hours do you work per week? ");
    scanf("%f", &hours_worked);

    printf("\nYour month salary is %.2f\n", 4 * salary_per_hour * hours_worked);
    
    return 0;
}