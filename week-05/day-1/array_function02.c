/*
 * Create a function that takes two arrays of characters and a number.
 * It should replace the contents of the first array from the given index
 * with the contents of the second array.
 * The function should return a number which tells whether it was successful:
 *    * If all is right it should return 0.
 *    * If the index is out of bounds it should return -1.
 *    * If the inserted content would be longer than the receiving array it should return 1 and leave the array as it is.
 * IMPORTANT: Think about what kind of arguments You need to make this happen and craft the function accordingly.
 *
 * Write code in the main function to test all scenarios and write out the result You need to check whether this works.
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

int overwrite(char *array1, char *array2, int pos_of_change);

int main()
{
    char array1[50] = "valamizenekutya";
    char array2[50] = "malol";

    puts(array1);
    puts(array2);

    printf("%d\n", overwrite(array1, array2, 0));

    puts(array1);

    return 0;
}

int overwrite(char *array1, char *array2, int pos_of_change)
{
    if (pos_of_change > strlen(array1))
        return -1;
    else if (strlen(array1) < pos_of_change + strlen(array2))
        return 1;
    else
        memcpy(&array1[pos_of_change], array2, strlen(array2));
        return 0;
}
