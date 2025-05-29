/*
Write a program that creates an Array (of integers).
The user is going to specify the values for the array.
Check if the array is:

Sorted ==> [1, 2, 5, 7, 8]
Really Sorted ==> [1, 2, 2, 3, 7]
Not sorted ==> [7, 3, 2, 1 ,5]
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main()
{
    int i;
    int array[SIZE];
    int flag = 1;

    for (i = 0; i < SIZE; i++)
        {
            printf("Enter a integer number: ");
            scanf("%d", &array[i]);
        }

    system("clear");

    printf("The array is [");
    for (i = 0; i < SIZE; i++)
        {
            printf(" %d ", array[i]);
        }
    printf("]\n\n");

    for (i = 0; i < SIZE - 1; i++)
        {
            if (array[i] > array[i + 1])
                {
                    flag = 0;
                    break;
                }
            else if (array[i] == array[i + 1])
                {
                    flag = 2;
                }
        }

    if (flag == 1)
        {
            printf("The array is Really sorted\n\n");
        }
    else if (flag == 2)
        {
            printf("The array is sorted\n\n");
        }
    else
        {
            printf("Not sorted\n\n");
        }

    return 0;
}