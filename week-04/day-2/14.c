#include <stdio.h>
#include <string.h>

void string_copy(char *dest, char *source);

int main()
{
    char my_string[] = "to be copied";
    char dest[50];

   //TODO: write a function, which copies a string to the 'dest' array, then print out in string format.

    string_copy(dest, my_string);

    return 0;
}

void string_copy(char *dest, char *source)
{
    for (int i = 0; i < strlen(source); i++) {
        dest[i] = source[i];
    }

    dest[strlen(source) + 1] = '\0';
    puts(dest);
}
