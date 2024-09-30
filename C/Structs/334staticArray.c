#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int y;
} Point;

int main()
{
    // Creating a static array of points
    Point pointsArray[5];
    int i;

    // Reading input to the first element in the array
    printf("Enter a first point 'x' coordinate: ");
    scanf("%d", &pointsArray[0].x);
    printf("Enter a first point 'y' coordinate: ");
    scanf("%d", &pointsArray[0].y);

    // Iterating over all of the Point Array (and getting input into each of
    // them)
    for (i = 0; i < 5; i++)
        {
            printf("Enter point #%d 'x' coordinate: ", i);
            scanf("%d", &pointsArray[i].x);
            printf("Enter point #%d 'y' coordinate: ", i);
            scanf("%d", &pointsArray[i].y);
        }

    // Acessing and printing all the values of each of the static array points
    for (i = 0; i < 5; i++)
        {
            // Nothe that each element of the array store an variable of type
            // Point (x,y)
            printf("Point #%d = (%d, %d)\n", i, pointsArray[i].x,
                   pointsArray[i].y);
        }

    return 0;
}