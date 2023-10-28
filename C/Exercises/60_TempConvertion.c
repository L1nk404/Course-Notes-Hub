/*
    1. Write a program that gets from the user a temperature ("double")
        in Celsius Degrees.
        Convert the temperature from Celsius Degrees to Fahrenheite Degrees
        and print it.
                        T(F) = T(C)*1.8 + 32

    2. Do the inverse.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    double celsius, farenheit, cel2far, far2cel;

    printf("Type the temperature in Celsius Degree: ");
    scanf("%lf", &celsius);
    printf("Type the temperature in Farenheit Degree: ");
    scanf("%lf", &far2cel);

    cel2far = celsius * 1.8 + 32;
    far2cel = (farenheit - 32)/1.8;

    printf(
        "\nThe conversion from Celsius Degree is %.2lf.\nThe conversion from Farenheit Degree is %.2lf\n",
         cel2far, far2cel
        );

    return 0;
}