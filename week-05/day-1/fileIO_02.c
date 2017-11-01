/*
 * Read the file You created fo the first exercise again.
 * Reverse the order of lines and write it out in a new file.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *rp = NULL;
    FILE *wp = NULL;
    char buffer[255];
    char temp = 0;
    int buff_length = 0;

    rp = fopen("vers.txt", "r");
    if (rp == NULL)
        return 1;

    wp = fopen("reversed.txt", "w");
    if (wp == NULL)
        return 2;

    while (fgets(buffer, 255, rp)) {
        buff_length = strlen(buffer);
        for (int i = 0; i <  buff_length / 2; i++) {
            temp = buffer[i];
            buffer[i] = buffer[buff_length - i - 2]; // -2: -1 due to \n; -1 due to arrays start at 0
            buffer[buff_length - i - 2] = temp;
        }
        printf("%s", buffer);
        fputs(buffer, wp);
    }

    fclose(rp);
    fclose(wp);

    return 0;
}
