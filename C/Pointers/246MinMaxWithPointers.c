#include <stdio.h>
#include <stdlib.h>

int findMinMax(int num1, int num2, int *pMax, int *pMin)
{

    if (num1 < num2)
        {
            *pMax = num1;
            *pMin = num2;
        }
    else
        {
            *pMax = num2;
            *pMin = num1;
        }
}

void main()
{
    int a = 117, b = 25;
    int max, min;

    findMinMax(a, b, &min, &max);
    // We bind the value of min and max to *pMax and *pMin

    printf("The max is %d\n", max);
    printf("The min is %d\n", min);
}