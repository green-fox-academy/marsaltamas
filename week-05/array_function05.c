/*
 * Take this array of characters: "2319834571976548721b1992456t831977451963782"
 * Create a function that takes an array of characters as the input. (Test it with the one above).
 * It should return an array of integers. Each representing a valid birth date year extracted from
 * the string of characters. (A valid birth year is either 19??, 20?? or 21??)
 * The 0th element of the returned array should be the number of valid birth years found. Then there should be
 * the birth years in each element.
 *
 * Create a main function to test this and print out the birth years in a new line each.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// takes an array of characters to search and its size as parameters
// returns the valid birthday as an int array
int *bd_finder(char array[], int size)
{
    int *return_array;
    int hit = 0;

    char dest[5];
    dest[4] = '\0';

    int temp = 0;

    // this loop determines how the size of the return array, based on the nr of hits
    for (int i = 0; i < size - 4; i++) {
    memcpy(dest, &array[i], 4); // saving ever 4 char to dest string
    temp = strtol(dest, NULL, 10); // checking if the int value of dest string is a valid birthday
    if ( temp > 1899 && temp < 2020)
        hit++;
    }

    return_array = (int*) malloc(hit * sizeof(int));

    if (!return_array) {
        perror("Error allocation memory.\n");
        exit(0);
    }

    memset(return_array, 0, hit);

    return_array[0] = hit;
    hit = 0;

    // loading up return array with valid birth dates
    for (int i = 0; i < size - 4; i++) {
        memcpy(dest, &array[i], 4);
        temp = strtol(dest, NULL, 10);
        if ( temp > 1899 && temp < 2020) {
            hit++;
            return_array[hit] = temp;
        }
    }
    return return_array;
}

int main()
{
    char char_array[] = "2319834571976541901872196520001b199245620002000200020002000200020002000200020002000200020002000t83197745196372019820";
    int size = sizeof(char_array) / sizeof(char);

    int *int_array = bd_finder(char_array, size);

    for (int i = 0; i < int_array[0] + 1; i++) {
        printf("array[%d]: %d\n", i, int_array[i]);
    }

    return 0;
}
