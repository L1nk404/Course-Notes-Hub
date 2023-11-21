// Write a program that reads a RxR point and print wich quadrant the poins is
// at.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    double x, y;

    printf("Enter the X coordinate: ");
    scanf("%lf", &x);
    printf("Enter the Y coordinate: ");
    scanf("%lf", &y);
    printf("\n");

    if (x > 0)
        {
            if (y > 0)
                printf("(%2.lf,%2.lf) is on 1st quadrant.\n", x, y);
            else
                printf("(%2.lf,%2.lf) is on 4st quadrant.\n", x, y);
        }
    else
        {
            if (y > 0)
                printf("(%2.lf,%2.lf) is on 2st quadrant.\n", x, y);
            else
                printf("(%2.lf,%2.lf) is on 3st quadrant.\n", x, y);
        }

    return 0;
}