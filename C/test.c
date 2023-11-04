#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, hundreds, tens, digit;

    printf("Choose a number: \n");
    scanf("%d", &num);

    if (num > 0)
        printf("1");
    else if (num == 0)
        printf("0");
    else
        printf("-1");

    return 0;
}