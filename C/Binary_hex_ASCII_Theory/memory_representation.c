#include <stdio.h>

int main() {
    char myChar1 = 'O';
    char myChar2 = 79;   // Dec representation of ASCII 'O'
    char myChar3 = 0x4F; // Hex representation of ASCII 'O'
    // The binary representation for ASCII 'O' is stored in some memory address.
    // In this case we are using 3 memory addresses to store the same value.

    printf("Character: %c \n", myChar1);
    printf("Decimal ASCII Code: %d \n", myChar1);
    printf("Hexadecimal ASCII Code: %X \n\n", myChar1);

    printf("Character: %c \n", myChar2);
    printf("Decimal ASCII Code: %d \n", myChar2);
    printf("Hexadecimal ASCII Code: %X \n\n", myChar2);

    printf("Character: %c \n", myChar3);
    printf("Decimal ASCII Code: %d \n", myChar3);
    printf("Hexadecimal ASCII Code: %X \n\n", myChar3);

    return 0;
}
