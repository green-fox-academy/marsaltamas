// Create a function that takes a string and a letter,
// than returns the count of occurrence of that letter in the string

#include <stdlib.h>
#include <stdio.h>


int main()
{

    char test_string[] = "abbcccdddd kk";
    char char_to_look_up = 'k';

    printf("%s\n", test_string);
    printf("%c\n", char_to_look_up);

    int hit = 0;

    for (int i = 0; i < strlen(test_string); i++) {

        if (test_string[i] == char_to_look_up) {
            hit++;
            printf("here: %d\n", hit);
        }
    }

    return 0;
}
