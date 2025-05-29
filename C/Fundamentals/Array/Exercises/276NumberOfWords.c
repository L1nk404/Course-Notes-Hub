#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numberOfWords(char *str);

int main()
{
    char str[1000];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    printf("The string have %d words\n", numberOfWords(str));
    return 0;
}

int numberOfWords(char *str)
{
    int wordsCount = 1;
    int i;

    for (i = 0; i < strlen(str); i++)
        {
            if (str[i] == 0x20) // white space ASCII code
                {
                    wordsCount++;
                }
            i++;
        }

    return wordsCount;
}