#include <stdio.h>
#include <stdlib.h>

int main(){
    int num;

    printf("Choose a int number: ");
    scanf("%d", &num);

    if (num % 2 == 0)
        printf("%d is is even\n\n", num);
    else
        printf("%d is odd", num );


    return 0;
}