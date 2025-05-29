#include <stdio.h>
#include <stdlib.h>

int returnMaxValue(int num1, int num2, int num3)
{
    if (num1 > num2)
        {
            if (num1 > num3)
                return num1;
            else
                return num3;
        }
    else if (num2 > num3)
        return num2;
    else
        return num3;
}

int main()
{
    int i, j, k;

    printf("Enter 3 values: ");

    scanf("%d", &i);
    scanf("%d", &j);
    scanf("%d", &k);

    printf("\nMax: %d\n\n", returnMaxValue(i, j, k));

    return 0;
}