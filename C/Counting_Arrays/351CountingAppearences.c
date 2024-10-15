/* ==========================================================================
Counting Appearances of Array with values {0,1,2}

    1. Given an array of a given size.
       The array consist only of values {0,1,2}.
    2. We would like to know:
        - Number of appearances of value 0 in the array
        - Number of appearances of value 1 in the array
        - Number of appearances of value 2 in the array
========================================================================== */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 15

int main()
{
    int i;
    int srcArray[SIZE] = {0, 1, 1, 2, 2, 0, 1, 0, 1, 1, 0, 1, 1, 2, 2};
    int countArray[3] = {0};

    for (i = 0; i < SIZE; i++)
        {
            countArray[srcArray[i]]++; // Couting the element in the respective
                                       // index
        }

    for (i = 0; i < 3; i++)
        {
            printf("The number #%d has %d occurences.\n", i, countArray[i]);
        }
    return 0;
}