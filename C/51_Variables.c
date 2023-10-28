#include <stdio.h>
#include <stdlib.h>

int main(){
    //Chalenge 1
    /*
    int currentYear;
    int age;
    int birthYear;

    scanf("%d", &currentYear);
    scanf("%d", &age);

    birthYear = currentYear - age;

    printf("You were born in %d \n\n", birthYear);
    */

    //Chalenge 2

    double Height, Width;
    double AreaOfRetangle;

    printf("Enter the height: ");
    scanf("%lf", &Height);
    printf("Enter the width: ");
    scanf("%lf", &Width);
    
    AreaOfRetangle = Height * Width;

    printf("The area of the rectangle is %.2lf \n", AreaOfRetangle);

    // printf("The area of retangle is %lf", AreaOfRetangle);
    return 0;
}