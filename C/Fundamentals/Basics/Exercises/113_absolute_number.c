#include <stdio.h>
#include <stdlib.h>

int main() {
    double number;

    printf("Enter a Real number: ");
    scanf("%lf", &number);

    if (number >= 0)
        printf("%.2lf", number);
    else
        printf("%2f", -1 * number);

    return 0;
}