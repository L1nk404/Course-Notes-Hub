#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;

    fp = fopen("myFile.txt", "r");
    char myChar1;

    if (fp != NULL) // file successfully oppened
        {
            printf("File successfully oppened\n");
            /*
            fgetc function
                arg: file pointer
                return: char

            Read a char inside the file
            */
            myChar1 = fgetc(fp);
            printf("the first char is '%c'\n", myChar1);

            // We can use the fgetc as a equivalent to getchar(), to read a char
            // from keyboard:
            fgetc(stdin);
        }
    else
        {
            printf("The oppening of the file has failed\n");
        }

    fclose(fp);

    return 0;
}