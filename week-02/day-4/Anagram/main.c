#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void not_anagrams();

int main()
{

    char word1[20] = "lasdf";
    char word2[20] = "asee";
    int flag = 1;

    puts("Please enter word1:");
    gets(word1);
    puts("Please enter word2:");
    gets(word2);

    for (int i = 0; i < strlen(word1); i++) {

        int word1count = 0;
        int word2count = 0;

        if (strlen(word1) != strlen(word2)) {
            printf("message from non equal: They are not anagrams.\n");
            not_anagrams();
            flag = 0;
            break;
        }

        if (!strchr(word2, word1[i])) {
            printf("message from letter not found: They are not anagrams.\n");
            not_anagrams();
            flag = 0;
            break;
        }

        for (int j = 0; j < strlen(word1); j++) {
            //lettercount in word1
            if (word1[i] == word1[j])
                word1count++;

            //lettercount in word2
            if (word1[i] == word2[j])
                word2count++;
        }

        if (word1count != word2count) {
            printf("message from letter count not matching: They are not anagrams.\n");
            not_anagrams();
            flag = 0;
            break;
        }
    }

    if (flag)
        printf("They are anagrams.\n");

    return 0;
}

void not_anagrams()
{
   // printf("message from non equal: They are not anagrams.\n");
}
