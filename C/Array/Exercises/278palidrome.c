/*
Write a program that reads a strings and it says if it is a
palindrome (string = reverse string)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[1000];
    int palindrome = 1;
    int i;
    int lenght, revereseChar;

    printf("Enter a string: ");
    scanf("%999s", str);

    lenght = strlen(str);

    for (i = 0; i < (lenght / 2); i++)
        {
            revereseChar = lenght - i - 1;
            if (str[i] != str[revereseChar])
                {
                    palindrome = 0;
                    break;
                }
        }

    if (palindrome == 1)
        {
            printf("The string \"%s\" is a palindrome\n", str);
        }
    else
        {
            printf("The string \"%s\" isn't is a palindrome\n", str);
        }

    return 0;
}