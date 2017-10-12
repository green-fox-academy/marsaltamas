#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void palindrom_searcher(char word1[]);

int main()
{
    char word1[40] = "racec ar";

    palindrom_searcher(word1);
    return 0;
}

void palindrom_searcher(char word1[])
{
    char word2[40] = "racdecar"; // array to store string segments for compare
    char word3[40] = "racacar"; // array to store string segments for compare

    // length of checked segment
    for (int length = 3; length <= strlen(word1); length++) {

        //position of checked segment's first char
        for (int position = 0; position < strlen(word1) - length + 1; position++) {

            int charcount = length; //setting marker to show end of check segment

            // reversing word segment and saving to word2 and word3 for comparing
            for (int i = position; i <= length + position; i++){

                word2[length - charcount] = word1[i];
                word3[charcount - 1] = word1[i];
                charcount--;
            }

            // adding closing zeros for checked strings
            word2[length] = '\0';
            word3[length] = '\0';

            // comparing strings with strcmp() and printing if they match
            if (!strcmp(word2, word3))
                printf("You found a partial palindrom: %s\n", word2);
        }
    }
}
