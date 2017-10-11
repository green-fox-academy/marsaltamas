#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char word1[20];
    char word2[20];

    puts("Please enter word1:");
    gets(word1);
    puts("Please enter word2:");
    gets(word2);

    printf("word1 %s\n", word1);
    printf("word2 %s\n", word2);

    int flag = 0;
    if (strlen(word1) != strlen(word2)) {
        flag = 1;
    }

        /*pseudo:
        checks equal length
        picks letter from word1
        checks if word2 has that letter
        checks how many times it is in word1
        if so, how many times word2 has that letter*/

    // i-th letter of word1
    for (int i = 0; i < strlen(word1); i++) {
        if (flag) {
            printf("They are not anagrams.\n");
            break;
        }
            // checks if word1[i] letter is available in word2
        for (int j = 0; j < strlen(word1); j++) {
            // if word1[i] available in word2, counting the occurances of word1[i] in word1

            int count_at_word1 = 0; // variable to keep track of how many times we can see letter in word1
            int count_at_word2 = 0; // variable to keep track of how many times we can see letter in word2

            if(word1[i] == word2[j]) {

                for (int k = 0; k < strlen(word1); k++) {
                    if (word1[i] == word1[k])
                        count_at_word1++;
                }

                for (int l = 0; l < strlen(word1); l++) {
                    if (word1[i] == word2[l])
                        count_at_word2++;
                }
            }

            if (count_at_word1 != count_at_word2) {
                flag = 1;
                break;
            } else {
                 count_at_word1 = 0;
                 count_at_word2 = 0;
            }


        }
    }

    if (!flag)
        printf("They are anagrams.\n");


    return 0;
}
