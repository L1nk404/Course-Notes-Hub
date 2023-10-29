// Make a program that receives a number with 3 digits and them prints the reverse number.

#include <stdio.h>
#include <stdlib.h>

int main(){
    int number , first_digit, second_digit, third_digit;
    printf("Type a number with 3 digits: ");
    scanf("%d", &number);

    first_digit = number / 100;
    second_digit = (number / 10) % 10;
    third_digit = number % 10;

    printf("\nThe reverse number is %d %d %d.\n", third_digit, second_digit, first_digit);

    return 0;
}