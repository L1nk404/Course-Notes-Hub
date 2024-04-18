#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

int main()
{
    // Let's start with 1D array:
    int i, j;
    int arr[SIZE];
    int arr2D[SIZE][SIZE];

    for (i = 0; i < SIZE; i++)
        {
            // %lu print the addressing in decimal representation
            // Notice that each element occupies 4 bytes
            printf("Element [%d] = %lu\n", i, &arr[i]);
        }

    printf("\n\n");

    for (i = 0; i < SIZE; i++)
        {
            for (j = 0; j < SIZE; j++)
                {
                    // Notice that the elements are stored one after one
                    printf("Element [%d][%d] = %lu\n", i, j, &arr2D[i][j]);
                }
        }
    return 0;
}