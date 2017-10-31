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

    char buffer[255];

    while (fgets(buffer, 255, fp)) {
       printf("%s", buffer);
    }

    printf("\n\n");

    fseek(fp, 0, SEEK_SET);

    int row_counter = 0;
    while (fgets(buffer, 255, fp)) {
        row_counter++;
    }

    printf("row_coutner: %d", row_counter);

    printf("\n\n");

    fseek(fp, 0, SEEK_SET);

    int char_count = -1;
    int vers_count = 0;
    char actual_char = '\0';

//    do {
//        actual_char = fgetc(fp);
//        char_count++;
//        if (actual_char == '\n')
//            char_count--;
//        if (actual_char == ' ')
//            char_count--;
//    } while (actual_char != EOF);
//
//    printf("char_count: %d", char_count);

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

    printf("verse count %d", vers_count);

    printf("\n\n");

    return 0;
}
