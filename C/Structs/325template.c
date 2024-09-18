/*
In C, a struct (short for "structure") is a user-defined data type that allows
you to group variables of different types together. It’s a way to store related
data, such as grouping an int, float, and char under a single entity. Each
variable within a struct is called a "member" or "field."

------------------

Imagine that we want to create a struct that hols any type of var, which type
the struct should be?
For that we will create fields. The general template is:

struct <struct-name>
{
    <type> <field-name>;
    <type> <field-name>;
    ...
    <type> <field-name>;
};

*/

int main()
{
    // example 1: date
    struct date
    {
        int day;
        int month;
        int year;
    };

    // example 2: point
    struct point
    {
        int x;
        int y;
    };

    // example 3: address
    struct address
    {
        char state[20];
        char city[10];
        char street[15];
        int number;
    };

    return 0;
}