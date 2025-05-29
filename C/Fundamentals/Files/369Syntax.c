/*---------------------------------------------------*/
/*-------------------- * Files * --------------------*/
/*---------------------------------------------------*/

#include <stdio.h> // we'll use a struct FILE from this library
#include <stdlib.h>

int main()
{
    // Step #1 - Creating a Pointer that points to a FILE type
    FILE *fp;

    // Step #2 - opening/access to a file
    /*
     fp = fopen(<file_name>, <type_of_operation>);

     Types of operation:
        - "w" - Writing
        - "r" - Reading
        - "a" - Appending
    */
    fp = fopen("myfile.txt", "w");

    // Step #3 - to make sure that the operation was successful
    if (fp != NULL)
        {
            printf("File oppened\n");
            // Code of working with the file
        }
    else
        {
            printf("Error on oppening file\n");
        }

    // Step #4 - cloe the file
    fclose(fp);

    return 0;
}