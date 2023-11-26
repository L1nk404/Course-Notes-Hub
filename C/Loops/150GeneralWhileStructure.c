
/*

Lesson 151 ~ 152

We have 3 types of loops:

1. While Loop
2. Do-While Loop
3. For Loop

In this lesson we'll talk about the While loop.

The executation of the loop body from top to bottom is called "iteration."

*/

#include <stdio.h>

int main()
{

    int count = 1; // a sort of control for while

    while (count < 10)
        {
            printf("*");
            count++; // Iancrimenting count
        }

    return 0;
}