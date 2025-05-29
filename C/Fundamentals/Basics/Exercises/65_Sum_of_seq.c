// Write a Program that prints the sum of a arithmetical sequence.

#include <stdio.h>
#include <stdlib.h>

int main(){

    int n1, step, term, nth, sum;

    printf("Type the 1st number of the sequence: ");
    scanf("%d", &n1);
    printf("Type the step of the sequence: ");
    scanf("%d", &step);
    printf("How many term do you want to sum? ");
    scanf("%d", &term);

    nth = n1 + (term - 1) * step;
    sum = (n1 + nth)*term/2;  // Also know as Gauss Sum

    printf("\nThe sum of the sequence is %d\n", sum);

    return 0;
    
}