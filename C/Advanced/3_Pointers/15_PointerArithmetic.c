#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;
    int grades[3] = {80, 90, 100};

    printf("grades starts at: %p\n",
           grades); // print the address of first element
    printf("grades starts at: %d\n",
           *grades); // print the value of first element
    printf("grades starts at: %p\n",
           &grades[0]); // print the address of first element

    /*
    Addition/Subtraction is done in chunks of the size of the data type the
    pointer is pointing to, for example:
        - int (4 bytes)
        - double (8 bytes)
        - char (1 byte)
    */
    printf("grades starts at: %p\n", grades + 1);
    printf("%d\n", sizeof(ptr));

    return 0;
}