#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void genericSwap(void *a, void *b, unsigned int size) // size > 0
{
    // size - specifies the number of bytes
    void *tempMemory = malloc(size);

    // Memmory Copy Function
    // void *memcpy(void *dest, const void * src, size_t num)
    memcpy(tempMemory, a, size); // copy  a -> tempMemory
    memcpy(a, b, size);          // copy  b -> a
    memcpy(b, tempMemory, size); // copy  tempMemory -> b

    // Release the memory allocated dynamically
    free(tempMemory);
}

int main()
{
    int num1 = 5, num2 = 7;
    double average1 = 12.3, average2 = 89.5;

    printf("num1 = %d, num2 = %d\naverage1 = %.2lf, average2 = %.2lf\n", num1,
           num2, average1, average2);

    genericSwap(&num1, &num2, sizeof(int));
    genericSwap(&average1, &average2, sizeof(double));

    printf("\nnum1 = %d, num2 = %d\naverage1 = %.2lf, average2 = %.2lf\n", num1,
           num2, average1, average2);
    return 0;
}