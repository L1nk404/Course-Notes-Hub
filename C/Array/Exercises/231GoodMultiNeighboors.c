/*
Write a program that creates an array of Integers.
The program should print if the array has at least one element with "good
neighboor":
    - An element with good neighboors has a value that equals to the multi-
      plication of both its neighbors (right and left).

Example:

A = [2, 6, 3, 5, 2] => 6 has good neighboors, because 2 * 3 = 6, different
                       than 5, because 3 * 2 != 5
*/

#include <stdbool.h> // Allows bool declaration
#include <stdio.h>
#include <stdlib.h> // Required for rand() e srand() func
#include <time.h>   // Required for time() func

int search_good_neighboor(int array[], int size)
{
    /*
    This function will search for a good neighboor in a given int array and
    returns a flag:
    - true  = The array have at least one good neighboor.
    - false = the array doesn't have neither good neighboor.
    */

    int k = 0;
    bool good_neighboor = false; // flag

    for (k = 1; k < size - 1; k++)
        // Since good neighboor number depends of left and right element, we
        // don't need to analyse the first neither the last element.

        {
            if ((array[k - 1] * array[k + 1]) == array[k])
                {
                    good_neighboor = true;
                    break;
                }
        }

    return good_neighboor;
}

int main()
{
    int i = 0;
    int SIZE = 5;
    int array[SIZE];

    srand(time(NULL));
    /*
    srand(time(NULL)) in this code has the objective of generate random numbers
    with the time(NULL) function's value. This number is the total seconds
    passed since 1st, January, 1970 until now.
    Doing this we can generate a different seed for each time the rand() func
    will execute, making it to generate always random numbers.
    See: https://linguagemc.com.br/valores-aleatorios-em-c-com-a-funcao-rand/
    */

    printf("The generated array is [");
    for (i == 0; i < SIZE; i++)
        {
            // rand() % 10 generates random numbers from 0 to 10
            array[i] = rand() % 10;
            printf("%d ", array[i]);
        }
    printf("]\n\n");

    if (search_good_neighboor(array, SIZE) == true)
        {
            printf("\033[92mThe array have at least one good "
                   "neighboor\033[0m\n\n");
        }
    else
        {
            printf(
                "\033[91mThe array doesn't have any good neighboor\033[0m\n\n");
        }

    return 0;
}