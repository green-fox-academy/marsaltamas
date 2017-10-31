/*
 * Take an array of characters, for example this: "In the year 2525, If man is still alive... In the Year 3535, In the Year 4545"
 * Create a function that takes an array of characters as an input, and a single character.
 * It should return all the indexes when teh character appears in an array of integers. Where the first number of the array
 * is how many occurrences of the character there are.
 *
 * Example: for the input ("Where is my cat? He?", 'e') the output should be: {3,2,4,18}
 *
 * Create a main function where You can test this function.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int* where_is_this_letter(char char_array[], int length, char to_locate)
{
    int position = -1;
    int hit = 0; // counts how many times to_locate char was found in string

    // setting up array to be returned, and counting the length of it
    for (int i = 0; i < length; i++) {
        if (char_array[i] == to_locate) {
            hit++;
        }
    }
    int *return_array = (int) malloc(hit * sizeof(int));

    // counting occurrences and saving to array
    hit = 0;

    for (int i = 0; i < length; i++) {
        if (char_array[i] == to_locate) {
            hit++;
            return_array[hit] = i;
        }
    }

    return_array[0] = hit;

    return return_array;
}

int main()
{
    char char_array[] = "eIn the year 2525, If man is still alive... In the Year 3535, In the Year 4545ee";

    int size = sizeof(char_array) / sizeof(char);
    char letter = 'e';
    int *position = where_is_this_letter(char_array, size, letter);

    for (int i = 0; i < position[0] + 1; i++) {
        printf("position[%d]: %d\n", i, position[i]);
    }

    return 0;
}
