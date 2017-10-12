void not_anagrams();
void find_out_if_they_anagrams();

void not_anagrams()
{
   printf("They are not anagrams.\n");
}

void find_out_if_they_anagrams()
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
            not_anagrams();
            flag = 0;
            break;
        }

        if (!strchr(word2, word1[i])) {
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
            not_anagrams();
            flag = 0;
            break;
        }
    }

    if (flag)
        printf("They are anagrams.\n");
}
