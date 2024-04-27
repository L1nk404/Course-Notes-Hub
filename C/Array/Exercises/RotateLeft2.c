#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 9

void printArray(int array[])
{
    int i;

    for (i = 0; i < SIZE; i++)
        {
            printf(" %d ", array[i]);
        }
}

// void genArray(int array[])
// {
//     int i;
//     int backupArray[SIZE];

//     srand(time(NULL));

//     printf("The generated array is [");
//     for (i = 0; i < SIZE; i++)
//         {
//             array[i] = rand() % 10;
//             printf(" %d ", array[i]);
//         }
//     printf("]\n\n");
// }

void rotateLeft_N_units(int array[], int n)
{
    int i, j = 0;
    int backupArray[SIZE];

    for (i = 0; i < SIZE; i++) // Copying array to backup
        {
            backupArray[i] = array[i];
        }

    for (i = 0; i < SIZE; i++) // Let's start the rotation
        {
            if (i == 0)
                {
                    array[SIZE - n] = backupArray[i];
                }
            else if (i < n)
                {
                    array[SIZE - i] = backupArray[n - i];
                }
            else
                {
                    array[j] = backupArray[n + j];
                    j++;
                }
        }
}

int main()
{
    int array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i, n;
    // genArray(array);

    printf("Enter n value: ");
    scanf("%d", &n);

    rotateLeft_N_units(array, n);

    printf("\n[");
    printArray(array);
    printf("]\n");

    return 0;
}