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

    char buffer[200];             // temporary buffer after lines read

    rp = fopen("vers.txt", "r"); // opening file to read
    if (rp == NULL)              // exit with 1 if failed
        return 1;

    wp = fopen("verses_reversed.txt", "w"); // opening file to read
    if (wp == NULL)                         // exit with 2 if failed
        return 2;

    int verse_length = 0;       // to store the length of a verse
    int max_verse_length = 0;   // stores the length of the longest verse
    int verse_count = 1;        // counts the num of verses

    while (fgets(buffer, 200, rp)) {
        verse_length = verse_length + strlen(buffer);
        if (buffer[0] == '\n') { // if it is an empty line, we found a new verse
            verse_count++;
            if (verse_length > max_verse_length)
                max_verse_length = verse_length;
            verse_length = 0;
        }
    }

    char **verse_buffer = (char **) malloc(verse_count * sizeof(char*)); // creating a 2D array to store verses

    for (int i = 0; i < verse_count; i++) {
        verse_buffer[i] = (char *) malloc(max_verse_length * sizeof(char));
        memset(verse_buffer[i], '\0', max_verse_length * sizeof(char));
    }

    fseek(rp, 0, SEEK_SET);
    verse_count = verse_count - 1;                  // using verse count as a counter in loop

    int reversed_verse_count = verse_count;         // used as iterator when writing to file

    while (fgets(buffer, 200, rp)) {
        strcat(verse_buffer[verse_count],  buffer); // adding verses to verse_count array
        if (buffer[0] == '\n')                      //detecting new verse
             verse_count--;
    }

    strcat(verse_buffer[verse_count], "\n\n");      // eliminating the effect of EOF

    for (int i = 0; i <= reversed_verse_count; i++) // saving file
        fprintf(wp, "%s", verse_buffer[i]);

    fclose(rp);
    fclose(wp);

    return 0;
}
