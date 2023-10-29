// Write a program that prints only the decimal part of a int number

#include <stdio.h>
#include <stdlib.h>

int main(){

    float number;
    int temp;

    printf("Enter a float number: ");
    scanf("%f", &number);

    temp = (float)number;  // implict casting here
    
    printf("The decimal part is %.2f", number - temp);

    return 0;
}