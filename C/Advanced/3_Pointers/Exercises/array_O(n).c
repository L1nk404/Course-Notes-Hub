#include <stdio.h>
#include <stdlib.h>

#define SIZE 6
#define BUFFER_SIZE

int checkSUM(int *arr, int value)
{
    int *iPtr, *jPtr;
    int j;

    // Here we have a O_n² complexity:
    // n-2 + n-1 + ..... 2 + 1 operations
    for (int i = 0; i < SIZE; i++)
    {
        j = SIZE - i;
        if (j == (i))
        {
            break;
        }

        *iPtr = arr[i];
        *iPtr = arr[j];

        if (arr[i] = arr[j] == value)
        {
            printf("%d, %d\n", i, j);
            return 1;
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