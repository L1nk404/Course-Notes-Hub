/*
Regarding the struct created on the past class named date, we can declare a
variable of type "struct date" using the following command:

    struct <struct_name> <variable_name>;

    or, in this specific situation:

    struct date myDate1, myDate2

*/

#include <stdio.h>

struct date
{
    int day;
    int month;
    int year;
};

int main()
{

    struct date myDate1,
        myDate2; // here we created 2 unitialized vars: myDate1, myDate2

    // Acessing the variable's fields

    myDate1.day = 10;
    myDate1.month = 3;
    myDate1.year = 2020;

    printf("%d/%d/%d\n", myDate1.day, myDate1.month, myDate1.year);

    return 0;
}