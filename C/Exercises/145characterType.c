/*
Write a program that should reveive a character from the user.
The program should print if the character is:

- Lowercase
- UpperCase
- Digit
- Other
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input;

    printf("Enter a character: ");
    scanf("%c", &input);

    if (input >= 0x41 && input <= 0x5A)
        printf("Uppercase.");
    else if (input >= 0x61 && input <= 0x7A)
        printf("Lowercase.");
    else if (input >= 0x30 && input <= 0x39)
        printf("Digit.");
    else
        printf("Other.");

    return 0;
}

// Teacher's solutions - much simplest:

// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
//     char input;

//     printf("Enter a character: ");
//     scanf("%c", &input);

//     if (input >= 'A' && input <= 'Z')
//         printf("Uppercase.");
//     else if (input >= 'a' && input <= 'z')
//         printf("Lowercase.");
//     else if (input >= '0' && input <= '9')
//         printf("Digit.");
//     else
//         printf("Other.");

//     return 0;
// }
