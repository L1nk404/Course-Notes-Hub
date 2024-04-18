#include <stdio.h>
#include <stdlib.h>

#define SIZE 11

void print_array(int array[SIZE][SIZE])
{
    int i, j;

    for (i = 1; i < SIZE; i++)
        {
            for (j = 1; j < SIZE; j++)
                {
                    printf("%5d", array[i][j]);
                }
            printf("\n");
        }
    printf("\n\n");
}

int main()
{
    int i, j;
    int mat[SIZE][SIZE];

    // Fill the values in the table
    for (i = 0; i < SIZE; i++)
        {
            for (j = 0; j < SIZE; j++)
                {
                    mat[i][j] = i * j;
                }
        }

    print_array(mat);

    return 0;
}