#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;

    fp = fopen("myFile.txt", "w");

    if (fp != NULL) // file successfully oppened
        {
        }
    else
        {
            printf("The oppening of the file has failed\n");
        }

    fclose(fp);

    return 0;
}