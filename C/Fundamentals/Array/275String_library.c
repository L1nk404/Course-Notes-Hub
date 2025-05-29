/*
Some funtctions of the library

1. strlen - Return the number of characters
2. strcpy - Copy the content of a string to other location
3. strcat - Concatenating
4. strcmp - Compare strings:
                https://www.geeksforgeeks.org/strcmp-in-c/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str1[5] = "Vlad";
    char str2[5];
    char str3[10] = "Dalv";
    char str4[5] = "Varc";

    // strlen(str)
    printf("Vlad is %d char length\n", strlen(str1));

    // strcpy(destination_str, source_str)
    strcpy(str2, str1); // Make sure that the str2 has enough memory
    printf("Printing %s\n", str2);

    // strcat(destination_str, source_str)
    printf("Contacatenating %s\n",
           strcat(str3, str1)); // make sure str_dest have enough memory

    // strcmp
    printf("sorting: %d\n", strcmp(str4, str1));

    return 0;
}
