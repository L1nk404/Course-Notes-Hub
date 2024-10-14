/*=================================================================
In low-level systems programming (e.g., device drivers, protocol stacks), it’s
common to use unions for type-punning, which is a way of treating the same data
as different types. This can be useful when dealing with hardware registers or
network protocols where the exact interpretation of data can change depending on
the context.

In this example, the union allows you to access an int as an array of bytes
=================================================================*/

#include <stdio.h>
#include <stdlib.h>

union Value
{
    int intVal;
    char bytes[4];
};

int main()
{

    union Value v;
    v.intVal = 0x12345678;
    printf("Byte 0: %02x\n", v.bytes[0]); // Access individual bytes
}