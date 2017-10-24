#include <stdio.h>
#include <string.h>

int first_word(char *string, int size, char *first);

int main()
{
    //TODO: write a function, which extracts the first word of a given string.
    //return with the word's length

    char str[] = "krumpli the first word.";
    char first[50];

    first_word(str, sizeof(str) / sizeof(str[0]), first);

    printf("first word was: %s\n", first);

    printf("length of first word was: %d\n", strlen(first));

    return 0;
}

int first_word(char *string, int size, char *first)
{
    strcpy(first, strtok(string, " "));

    return  strlen(first);
}
