#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main()
{
    int i, j, counter;
    int X;
    char array[SIZE] = {'a', 'k', 'l', 'z', 'k', 'o', 'u', 'z', 'k', 'o'};
    char countArray[SIZE] = {'.'};

    for (i = 0; i < SIZE; i++)
        {
            counter = 0;
            for (j = 0; j < SIZE; j++)
                {
                    if (array[i] == array[j])
                        {
                            counter++;
                        }
                }

            array[j] = array[counter];
        }

    for (i = SIZE; i > 0; i--)
        {
            if (countArray[i] != '.')
                {
                    printf("A letra que mais apareceu foi %c, tendo %d "
                           "aparições\n",
                           countArray[i], i);
                    break;
                }
        }

    return 0;
}