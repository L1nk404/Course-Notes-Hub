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

int equalPoints(Point p1, Point p2)
{
    if (p1.x == p2.x && p1.y == p2.y)
        return 1;
    else
        return 0;
}

int compareByAge(Employee e1, Employee e2)
{
    if (e1.age == e2.age)
        return 1;
}

int main()
{
    Point point1 = {1, 2}, point2 = {4, 1};

    if (equalPoints(point1, point2) == 1)
        {
            /* code related to the fact that the points are equal*/
        }

    return 0;
}