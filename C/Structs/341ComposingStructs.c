#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int y;
} Point;

// Here we can create a struct composed with Point
typedef struct
{
    Point center;
    double radius;
} Circle;

int main()
{
    Point p1 = {1, 2};
    Circle c1;

    c1.radius = 3.3;
    c1.center = p1;

    printf("Center: (%d,%d), Radius:% .2lf\n\n", c1.center.x, c1.center.y,
           c1.radius);

    return 0;
}