/*
 Exercise:
    - Write a function that receives a Sroted (smallest->largest) Array of
    elements.
    - The function also receives a "value". The function should find if
    there's a sum of 2 elements in the array that equals to the received
    "value".
    - If there are such 2 elements, then return 1, and pass their indexes
    - Else, return 0, and pass for both of them the value 0.
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 6
#define BUFFER_SIZE

int checkSUM(int *arr, int value)
{
    int *iPtr, *jPtr;

    // Here we have a O_n² complexity:
    // n-2 + n-1 + ..... 2 + 1 operations
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            *iPtr = arr[i];
            *iPtr = arr[j];

            if (arr[i] = arr[j] == value)
            {
                printf("%d, %d\n", i, j);
                return 1;
            }
        }
    }
    *iPtr = 0;
    *jPtr = 0;
    return 0;
}

int main()
{
    int value = 0;
    int array[SIZE] = {2, 3, 8, 13, 15, 17};

    printf("Enter a value: ");
    scanf("%d", &value);

    int flag = checkSUM(array, value);

    printf("\n[");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }
    printf("]\n\n");

    return 0;
}
