#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

void print_array(int array[SIZE][SIZE])
{
    int i, j;

    for (i = 0; i < SIZE; i++)
        {
            for (j = 0; j < SIZE; j++)
                {
                    printf("%5d", array[i][j]);
                }
            printf("\n");
        }
    printf("\n\n");
}

int main()
{

    int mat[SIZE][SIZE] = {}; // We have to inicializate the array

    printf("Enter a value:");
    scanf("%d", &mat[1][2]);
    printf("\n");

    print_array(mat);

    return 0;
}