/*
 * Read the file You created in the first exercise.
 * Reverse the order of the verses.
 * Write it out in a new file.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *rp = NULL;
    FILE *wp = NULL;

    char buffer[200];

    rp = fopen("vers.txt", "r");
    if (rp == NULL)
        return 1;

    wp = fopen("verses_reversed.txt", "w");
    if (wp == NULL)
        return 2;

    int verse_length = 0;
    int max_verse_length = 0;
    int verse_count = 1;

    while (fgets(buffer, 200, rp)) {
        verse_length = verse_length + strlen(buffer);
        if (buffer[0] == '\n') {
            verse_count++;
            if (verse_length > max_verse_length)
                max_verse_length = verse_length;
            verse_length = 0;
        }
    }

    char **verse_buffer = (char **) malloc(verse_count * sizeof(char*));

    for (int i = 0; i < verse_count; i++) {
        verse_buffer[i] = (char *) malloc(max_verse_length * sizeof(char));
        memset(verse_buffer[i], '\0', max_verse_length * sizeof(char));
    }

    printf("\n\nversecount %d\n", verse_count);
    printf("maxverse length %d\n", max_verse_length);


    fseek(rp, 0, SEEK_SET);
    verse_count = verse_count - 1;

    int reversed_verse_count = verse_count;

    while (fgets(buffer, 200, rp)) {
        strcat(verse_buffer[verse_count],  buffer);
        if (buffer[0] == '\n')
             verse_count--;
    }

    strcat(verse_buffer[verse_count], "\n\n");


    for (int i = 0; i <= reversed_verse_count; i++)
        fprintf(wp, "%s", verse_buffer[i]);

    fclose(rp);
    fclose(wp);

    return 0;
}
