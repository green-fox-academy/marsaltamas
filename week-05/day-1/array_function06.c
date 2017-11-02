/*
 * Take an array of characters, for example this: "In the year 2525, If man is still alive... In the Year 3535, In the Year 4545"
 * Create a function that takes an array of characters as an input, and a single character.
 * It should return the first index when this character appears.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// takes an array of chars to search for, the length of this array and a character to_locate
// returns the position where the letter located first. if letter was not found, returns -1.
int where_is_this_letter(char char_array[], int length, char to_locate)
{
    int position = -1;

    for (int i = 0; i < length; i++) {
        if (char_array[i] == to_locate) {
            position = i;
            break;
        }
    }

    return position;
}

int main()
{
    char char_array[] = "In the year 2525, If man is still alive... In the Year 3535, In the Year 4545";

    int size = sizeof(char_array) / sizeof(char);
    char letter = 'Y';
    int position = where_is_this_letter(char_array, size, letter);

    if (position > -1)
        printf("Position of letter \"%c\" is \"%d\".\n", letter, position);
    else
        printf("Letter \"%c\" is not in the string.\n", letter);
    return 0;
}
