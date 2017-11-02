/*
 * Take the file You created in the previous exercise.
 * Read it again and write some statistics about it:
 *    * How many lines
 *    * How many characters (with and without spaces)
 *    * How many verses does it have
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp = fopen("vers.txt", "r");
    if (fp == NULL)
        return 1;

    char buffer[255];

/* ================printing poem================ */

    while (fgets(buffer, 255, fp)) {
       printf("%s", buffer);
    }

    printf("\n");

/* ================counting rows================ */

    fseek(fp, 0, SEEK_SET);

    int row_counter = 0;
    while (fgets(buffer, 255, fp)) {
        if (buffer[0] != '\n')
            row_counter++;
    }

    printf("row_coutner: %d", row_counter);

    printf("\n\n");

/* ================counting verses================ */

    fseek(fp, 0, SEEK_SET);

    int char_count = 0;
    int vers_count = 0;
    char actual_char = '\0';

    do {
        actual_char = fgetc(fp);
        if (actual_char != '\n')
            char_count++;
        else {
            if (char_count == 0)
                vers_count++;
            char_count = 0;
        }
    } while (actual_char != EOF);

    printf("verse count: %d", vers_count);

    printf("\n\n");

/* ================counting characters with spaces================ */

    fseek(fp, 0, SEEK_SET);

    char_count = -1;
    actual_char = '\0';

    do {
        actual_char = fgetc(fp);
        if (actual_char != '\n')
            char_count++;
    } while (actual_char != EOF);

    printf("char count with spaces: %d", char_count);

    printf("\n\n");

/* ================counting characters w/o spaces================ */

    fseek(fp, 0, SEEK_SET);

    char_count = -1;
    actual_char = '\0';

    do {
        actual_char = fgetc(fp);
        if (actual_char != '\n' && actual_char != ' ')
            char_count++;
    } while (actual_char != EOF);

    printf("char count w/o spaces: %d", char_count);

    printf("\n\n");

    return 0;
}
