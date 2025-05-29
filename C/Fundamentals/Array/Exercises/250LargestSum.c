/*
Write a program that should calculate and print the Largest Sum of two Adjacent
Element in the Array
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 6

int genArray(int pArray[])
{
    /*
    In C, when you pass an array to a function, what is actually passed is a
    pointer to the first element of the array. So, even though it might not look
    like you’re using a pointer, you are in fact using a pointer when you pass
    an array to a function. In the genArray function, pArray is a
    pointer to the first element of the array. When you modify pArray[i], you’re
    actually modifying the ith element of the array in the memory. So, the
    changes you make inside the genArray function are reflected in the main
    function.
    */

    int i;

    srand(time(NULL)); // See 231GoodMultiNeighboirs.c for more srand info

    printf("The generated array is [");
    for (i == 0; i < SIZE; i++)
        {
            pArray[i] = rand() % 9;
            printf(" %d ", pArray[i]);
        }
    printf("]\n\n");
}

int main()
{
    int i;
    int sum, LargestSum = 0;
    int arr_sumElements[2];
    int array[SIZE] = {};

    genArray(array);

    for (i = 0; i < SIZE - 1; i++)
        {
            sum = array[i] + array[i + 1];

            if (sum > LargestSum)
                {
                    LargestSum = sum;
                    arr_sumElements[1] = array[i];
                    arr_sumElements[2] = array[i + 1];
                }
        }

    printf("The Largest Sum is %d and it is result of the sum of %d and %d\n\n",
           LargestSum, arr_sumElements[1], arr_sumElements[2]);

    return 0;
}