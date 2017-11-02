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

    char buffer[255];

    rp = fopen("vers.txt", "r");
    if (rp == NULL)
        return 1;

    wp = fopen("verses_reversed.txt", "w");
    if (wp == NULL)
        return 2;

    fpos_t position;
    char temp = 0;

    do {
        temp = fgetc(rp);
        fputc('x', wp);
        fgetpos(wp, &position);
    } while (temp != EOF);

    fgetpos(wp, &position);

    fseek(rp, 0, SEEK_SET);
    fseek(wp, 0, SEEK_SET);

    char *verse_buffer = (char*)malloc(200 * sizeof(char));

    while (fgets(buffer, 200, rp)) {
        if (buffer[0] != '\n') {
            strcat(verse_buffer, buffer);
        } else {
            strcat(verse_buffer, "\n");
            position = position - (fpos_t) strlen(verse_buffer);
            fsetpos(wp, &position);
            fprintf(wp, "%s", verse_buffer);
            free(verse_buffer);
            verse_buffer = (char*)malloc(200 * sizeof(char));
        }
    }

    return 0;
}
