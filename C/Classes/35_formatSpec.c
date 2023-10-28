#include <stdio.h>
#include <stdlib.h>

int main(){
    // The %d is used for integer numbers
    printf("I am %d years old, I was borned in the year %d\n", 2023-1998, 1998);
    // For a float number we have to use %f, we can use %.xf for determine the x number of decimal digits
    printf("My average grade is: %.1f\n", 93.7);
    scanf("How many years do you have? %d");
    return 0;
}
