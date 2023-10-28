#include <stdio.h>
#include <stdlib.h>

int main(){
    float a = 5.5, b = 4.6;
    float temp;  // we create a 3rd var called temp to swap the values of a and b.

    printf("a = %f\n", a);
    printf("b = %f\n", b);

    temp = a;
    a = b;
    b = temp;

    printf("a = %f\n", a);
    printf("b = %f\n", b);
    

    return 0;
}