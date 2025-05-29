#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1 = 1, num2 = 3;
    int min;

    // To find the min value we can use if and else statement, but there is a
    // easiest way to do that, and it its with Ternary Operations:

    min = (num1 > num2) ? printf("num2 %d (True Statement)", num2)
                        : printf("num1 %d (False Statement)", num1);

    return 0;
}