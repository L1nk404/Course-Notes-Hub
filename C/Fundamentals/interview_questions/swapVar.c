#include <stdio.h>
#include <stdlib.h>

int main()
{
    int var1 = 10;
    int var2 = 20;

    printf("Var1 = %d, Var2 = %d\n", var1, var2);

    /*
    a = a + b
    b = a - b = (a + b) - b = a
    a = a - b = a - (a - b) = b
    */

    var1 = var1 + var2; // 10 + 20 = 30
    var2 = var1 - var2; // 30 - 20 = 10 -> Initial var
    var1 = var1 - var2; // 30 - 10 = 20 -> Initial Var2

    printf("Var1 = %d, Var2 = %d\n", var1, var2);

    return 0;
}