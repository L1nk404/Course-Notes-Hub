#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, hundreds, tens;
    printf("Enter a int: ");
    scanf("%d", &num);

    if (num < 10)
        printf("The number has 1 digit.");
    else if (num < 100)
        printf("the number is a double digit number.");
    else if (num <= 999)
        printf("The number is a triple digit number.");
    else
        printf("the number has more than 3 digits.");

    return 0;
}