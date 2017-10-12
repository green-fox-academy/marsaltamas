#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *palindrom(char word1[]);

int main()
{
    char word1[25] = "racecar";
    char word2[25] = "racdecar";
    char word3[25] = "racacar";

    printf("%d\n", strcmp(word1, palindrom(word1)));

    printf("the word1 is %s\n", palindrom(word1));
    printf("the palindrom is %s\n", palindrom(word1));

    // length of checked segment
    for (int length = 3; length <= strlen(word1); length++) {
        //position of checked segment's first char
        for (int position = 0; position < strlen(word1) - length + 1; position++) {
            // reversing word segment and checking
            printf("\nsegment to compare:\n");
            for (int i = position; i < position + length; i++) {
                printf("%c", word1[i]);
            }
            printf("\n---------\n");

            int charcount = length;

            for (int i = position; i <= length + length / 2; i++){

                word2[length - charcount] = word1[i];
                word3[charcount - 1] = word1[i];
                charcount--;
            }
            word2[length] = '\0';
            word3[length] = '\0';

            printf("word 2 is %s\n", word2);
            printf("word 2 is %s\n", word3);

            if (!strcmp(word2, word3))
                printf("You found a partial palindrom: %s\n", word2);
        }
    }

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
