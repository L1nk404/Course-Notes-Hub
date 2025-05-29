// Struct Operators and Relations
// Usage of "Relational Operators"

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int y;
} Point;

typedef struct
{
    char name[10];
    float age;
    int id;
} Employee;

int main()
{
    Point p1 = {3, 2}, p2 = {2, 6};

    /*
    if (p1 < p2)
        {
            // Error #1 - What fields is used to decide the result?
        }

    if (p1 == p2)
        {
            // Error #2 - What fields are we interested? All of them? Just a
    few?
        }
    */

    return 0;
}
