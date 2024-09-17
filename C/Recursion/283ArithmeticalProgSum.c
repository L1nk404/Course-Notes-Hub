/*
1. Receive a natural number (num)
2. Return the Sum of Arithmetical Progression from 1 to num

===============

In that case we can simply do a for loop, but let's use recursion.
A recursion is a function that calls himself up to up again until a break
condiction, like  a loop does.
*/

#include <stdio.h>
#include <stdlib.h>

int sumUpTo(int num)
{
    if (num == 1) // Trivial solution
        {
            return 1;
        }

    return num + sumUpTo(num - 1); // calls itself until num == 1, which
                                   // triggers the trivial solution
}

int main()
{
    int num, result;

    printf("Enter a number: ");
    scanf("%d", &num);

    result = sumUpTo(num);

    printf("The sum is %d\n\n", result);

    return 0;
}

/*
Explanation of code:

1. How does the function saves the value of the sum?

In recursion, each call to the function creates a new stack frame (a place where
the local variables and the state of that particular function call are stored -
See Assembly class 27). When a function calls itself recursively, each call
pushes a new frame onto the stack.

2. Why doesn't return 1 when the trivial case is triggered?

When the base case (num == 1) is reached, the function does return 1. However,
that 1 is not immediately the final result because the recursion continues to
unwind. The recursive calls are stacked on top of each other, and the results
from each recursive level are combined as the function returns back through the
stack.
*/