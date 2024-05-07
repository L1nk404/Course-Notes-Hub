/*
1. Write a function that takes a string and returns its lenght.

2. Write a program that:
    a. Reads a string from a user.
    b. Calls the function at (1).
    c. Prints the lenght to the string.
*/

#include <stdio.h>
#include <stdlib.h>

int len(char *str);

int main()
{
    char str[1000];
    int totalLenght;

    printf("Enter a 1 word string: ");
    scanf("%999s", str);

    totalLenght =
        len(str); // str holds the memory addr of the frist element of the array

    printf("The string is '%s', their lenght is: %d\n\n", str, totalLenght);

    return 0;
}

int len(char *str)
{
    int lenght = 0;
    int i = 0;

    while (str[i] != '\0')
        {
            i++;
            lenght++;
        }

    return lenght;
}