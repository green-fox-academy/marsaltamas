#include <stdio.h>
#include <string.h>

    //TODO: write a c program which, splits a string to words by space
	//solve the problem with the proper string.h function

int main()
{
    printf("Type in a sentence:\n");
    char string[200];
    gets(string);
    char *ptr;

    ptr = strtok(string, " ");

    while (ptr != NULL) {
        printf("%s\n", ptr);
        ptr = strtok(NULL, " ");
    }

    return(0);
}
