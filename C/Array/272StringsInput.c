#include <stdio.h>
#include <stdlib.h>

int main()
{

    char firstName[10];

    printf("\n\nEnter your first name: ");
    scanf("%9s",
          firstName); // %s specifies that we are reading a string.
                      // We need to limit the lenght of the string that we'll
                      // receive, so, %9s works like a sort of security
                      // mechanism of that, limiting the lenght to 9 characters.
                      // This prevents buffer overflow.

    printf("\nHello %s.\n\n",
           firstName); // We can print a string in a line code by %s

    // Now let's see a example with a statement:

    char str[20];

    // In this case we can't use the scanf() funcion, because that function just
    // captures the elements before a blank space, so, with we use scanf to
    // input "Hello World", the str will be just "Hello"
    // To avoid this problem, we simply use gets() function that can read text.

    printf("Enter a 2 world string: ");
    gets(str); // Note that this option is not secure due to it not having
               // length limitation, making it vulnerable to buffer overflow

    printf("\n%s\n\n", str);

    return 0;
}