/*
1. Print all unique element in an Array
2. Count the unique elements
*/

#include <stdbool.h>
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

int main()
{
    int i, j, k, l = 0, count = 0;
    int array[SIZE];
    int flag = -1;

    genArray(array);

    for (i = 0; i < SIZE; i++)
        {
            for (j = i + 1; j < SIZE; j++)
                {
                    if (array[i] == array[j])
                        {

                            array[i] = array[j] = flag;
                        }
                }
            if (array[i] != -1)
                {
                    printf("%d ", array[i]);
                    count++;
                }
        }
    printf("\ncount = %d\n\n", count);
    return 0;
}