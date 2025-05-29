#include <stdio.h>
#include <stdlib.h>

int main(){
    int x, x2, x4, x6, x8;

    printf("Enter the X value: ");
    scanf_s("%d", &x);
    x2 = x * x;
    x4 = x2 * x2;
    x6 = x4 * x2;
    x8 = x4* x4;

    printf("x^2 = %d, x^4 = %d, x^6 = %d, x^8 = %d", x2, x4, x6, x8);

    return 0;
}