// Write a Program that prints the n-th term of a arithmetical seq.

#include <stdio.h>
#include <stdlib.h>

int main(){

    int n1, step, term, nth;

    printf("Type the 1st number of the sequence: ");
    scanf("%d", &n1);
    printf("Type the step of the sequence: ");
    scanf("%d", &step);
    printf("Wich term of sequence do you want to calculate? ");
    scanf("%d", &term);

    nth = n1 + (term - 1) * step;

    printf("\nThe n-th term is %d", nth);

    return 0;
    
}