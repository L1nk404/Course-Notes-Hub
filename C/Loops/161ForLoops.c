#include <stdio.h>

int main()
{
    int num;
    int i;

    printf("Hello! Enter a numbe: ");
    scanf("%d", &num);

    // Lets print just the odd numbers
    for (i = 1; i <= num; i = i + 2)
        {
            printf("%d ", i);
        }

    return 0;
}