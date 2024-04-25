/*
Write a program that rotate left a given array by 1 position
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void genArray(int array[])
{
    int i;

    srand(time(NULL));

    printf("The generated array is [");
    for (i = 0; i < SIZE; i++)
        {
            array[i] = rand() % 10;
            printf(" %d ", array[i]);
        }
    printf("]\n\n");
}

void rotateLeft(int array[])
{
    int i;
    int backupArray[SIZE];

    for (i = 0; i < SIZE; i++) // Copying array to backup
        {
            backupArray[i] = array[i];
        }

    printf("The backup array is [");
    for (i = 0; i < SIZE; i++)
        {
            printf(" %d ", backupArray[i]);
        }
    printf("]\n\n");

    for (i = 0; i < SIZE; i++) // Let's start the rotation
        {
            // That if is important because i + 1 == SIZE, so it's out of array
            // range
            if (i + 1 == SIZE)
                {
                    array[SIZE - 1] = backupArray[0];
                }
            else
                {
                    array[i] = backupArray[i + 1];
                }
        }
}

int main()
{
    int i;
    int array[SIZE];

    genArray(array);
    rotateLeft(array);

    printf("The rotated array is [");
    for (i = 0; i < SIZE; i++)
        {
            printf(" %d ", array[i]);
        }
    printf("]\n\n");

    return 0;
}