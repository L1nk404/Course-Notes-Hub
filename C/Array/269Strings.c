#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    char str[] = "Hello World!";

    while (str[i] != '\0')
        {
            printf("%c", str[i]);
            i++;
        }
    printf("\n");

    return 0;
}