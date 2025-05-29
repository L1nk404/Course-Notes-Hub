/*
We use type def to give an alias to an type using the following syntax:

    typedef <type> <name>

for example, if we want to give the name "GRADE" for an int type we can use

    typedef int GRADE

and initialize in that way:

    GRADE math;
    GRADE physics;

For structs this can be very useful saving a lot of time
Using the typedef option, makes it easier to create vars
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct date
{
    int day;
    int month;
    int year;
} Date;

Date inputDate();

void printDate(Date dt);

int main()
{
    Date Mydate1;

    Mydate1 = inputDate();

    printDate(Mydate1);

    return 0;
}

Date inputDate() // function with Date type
{
    Date dt;
    printf("Enter a day (1-31): ");
    scanf("%d", &dt.day);
    printf("Enter a month (1-12): ");
    scanf("%d", &dt.month);
    printf("Enter a year (yyyy): ");
    scanf("%d", &dt.year);

    return dt;
}

void printDate(Date dt) { printf("\n%d/%d/%d\n", dt.day, dt.month, dt.year); }