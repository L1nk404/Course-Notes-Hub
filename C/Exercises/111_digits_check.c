#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, hundreds, tens;
    printf("Enter a int: ");
    scanf("%d", &num);

    hundreds = num / 100;
    tens = (num % 100) / 10;

    if (hundreds != 0)
        printf("The number has 3 digits\n");
    else if (tens != 0)
        printf("The number has 2 digits\n");
    else
        printf("The number has 1 digit\n");

    return 0;
}