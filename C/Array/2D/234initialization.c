#include <stdio.h>
#include <stdlib.h>

void print_array(int m, int n, int array[m][n])
{
    int i, j;

    for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
                {
                    printf("%d ", array[i][j]);
                }
            printf("\n");
        }
    printf("\n\n");
}

int main()
{
    /* We can initializate a 2D array in differents ways: */
    int i, j;

    // Standard way:
    int standard[2][3] = {{1, 2, 3}, {4, 5, 6}};
    printf("Standard way:\n");
    print_array(2, 3, standard);

    // Incomplete values in the Internal Curly brackets
    // In this mode the array will be completed with 0
    int incomp[4][3] = {{5, 6}, {7, 8, 9}, {}, {0, 2}};
    printf("Incomplete values in the Internal Curly brackets:\n");
    print_array(4, 3, incomp);

    // Excessively values in the internal Curly brackets
    // We fill the array with elements from the left to the right
    int exc[3][3] = {5, 2, 1, 6, 5};
    printf("Excessively values in the internal Curly brackets:\n");
    print_array(3, 3, exc);

    return 0;
}
