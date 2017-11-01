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

    rp = fopen("verses_to_reverse.txt", "r");
    if (rp == NULL)
        return 1;

    wp = fopen("verses_reversed.txt", "w");
    if (wp == NULL)
        return 2;

    int rows_count = 0;

    while (fgets(buffer, 255, rp)) {
        rows_count++;
        fprintf(wp, "\n");
    }

    fseek(rp, 0, SEEK_SET);
   // fseek(wp, 0, SEEK_SET);

    int row_position = 0;

    while (fgets(buffer, 1000, rp)) {
        fseek(wp, rows_count - row_position, SEEK_CUR);
        fputs(buffer, wp);
        row_position++;
    }

    fclose(rp);
    fclose(wp);

    return 0;
}
