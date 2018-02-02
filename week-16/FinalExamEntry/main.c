/*
 * Final Exam Entry
 * Marsal Tamas
 * Task 7:
 * Create a function that takes a string and a letter,
 * than returns the count of occurrence of that letter in the string
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * returns the count of occurrence of
 * param: char_to_look_up in
 * param: string
 * return: occurrence as int
 * note: this function accepts only '\0' terminating strings
 */
int letter_in_string_num_times(char string[], char char_to_look_up);

int main()
{
    char test_string[] = "a bb ccc dddd 55555 A";
    char char_to_look_up = 'A';

    printf("Chart to look up: %c\n"
           "Found in string: %s\n"
           "%d time(s)\n", char_to_look_up, test_string,
           letter_in_string_num_times(test_string, char_to_look_up));

    return 0;
}

int letter_in_string_num_times(char string[], char char_to_look_up)
{
    int hit = 0;

    for (int i = 0; i < strlen(string); i++) {

        if (string[i] == char_to_look_up) {
            hit++;
        }
    }

    return hit;
}
