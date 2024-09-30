#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;
    float y;
} Point;

int main()
{
    // Declaring a "Point" without initialization
    Point p1;

    // Initializig a "Point" varible (members in order)
    Point p2 = {5, 7.1};

    // Using designated Initializer
    Point p3 = {.x = 3, .y = 4.2};

    // Using designated initializer (out of order)
    Point p4 = {.y = 10.98, .x = 2};

    // Designated Initializer (other member are initialized with 0)
    Point p5 = {.x = 1};

    return 0;
}
