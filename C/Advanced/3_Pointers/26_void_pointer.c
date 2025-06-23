/*
The Void universal approach

What is a "void *"?
- It's use to point to an address of ANY TYPE of data

Why is it useful?
1. "General purpose" functions
2. When we don't know the returned pointer type
3. Dynamic Memory Allocation
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 10;
    void *ptr = &a;

    // Every time we want to ascces, we need to made
    // an explict type casting
    printf("%d\n", *(int *)ptr);

    return 0;
}