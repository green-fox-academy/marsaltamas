#include <stdlib.h>
#include <stdio.h>

char *palindrom(char word1[]);

int main()
{
    char word1[25] = "alma malma";

    printf("the palindrom is %s", palindrom(word1));

    return 0;
}

char *palindrom(char word1[])
{
    char temp = 0;

    printf("The original word was: %s.\n", word1);

    for (int i = 0; i < strlen(word1)  / 2; i++) {

        temp = word1[i];
        word1[i] = word1[strlen(word1) - i - 1];
        word1[strlen(word1) - i - 1] = temp;
    }

    return word1;
}
