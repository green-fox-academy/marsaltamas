#include <stdlib.h>
#include <stdio.h>

char *create_palindrom(char word1[]);

int main()
{
    char word1[25] = "kerekes 5";

    printf("%s",create_palindrom(word1));

    return 0;
}

char *create_palindrom(char word1[])
{
    char word2[25];

    printf("The original word was: %s.\n", word1);

    for (int i = 0; i < strlen(word1); i++) {
        word2[strlen(word1) - i - 1] = word1 [i];
    }

    word2[strlen(word1)] = '\0';

    return strcat(word1, word2);
}
