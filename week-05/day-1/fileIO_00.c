/*
 * Create a text file with You favourite poem in it. If You don't have one, just take one.
 *
 * Read the poem from the file and print it on the console.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp = NULL;
    FILE *wp = NULL;
    FILE *rbinary = NULL;
    FILE *wbinary = NULL;
    char *binaryreader = NULL;
    char *binarywriter = NULL;

    fp = fopen("vers.txt", "r");
    if (fp == NULL)
        return 1;

    wp = fopen("copy.txt", "w+");
       if (wp == NULL)
        return 1;

    char buffer[255];

    while (fgets(buffer, 255, fp)) {
        printf("%s", buffer);
        fputs(buffer, wp);
    }

    fclose(fp);
    fclose(wp);

    rbinary = fopen("vers.txt", "r");
    if (rbinary == NULL)
        return 1;

    wbinary = fopen("binary.raw", "w+");
    if (wbinary == NULL)
        return 1;

    binaryreader = rbinary;
    binaryreader = rbinary;

    while (fgets(buffer, 255, rbinary)) {
        fwrite(buffer, strlen(buffer), 1, wbinary);
    }

    fclose(rbinary);
    fclose(wbinary);

    printf("\n");

    return 0;
}
