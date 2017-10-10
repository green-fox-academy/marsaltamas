#include <stdio.h>

int main() {
    char char_array[4] = {'a', 'b', 'c', 'd'};
    char char_array_the_same[] = "abcd";

	//TODO:
    // Print out the two arrays character-by-character


    for (int i = 0; i < strlen(char_array); i++)
    {
        printf("%c\n", char_array[i]);
    }

    printf("\n");

    for (int i = 0; i < strlen(char_array_the_same); i++)
    {
        printf("%c\n", char_array_the_same[i]);
    }

	//TODO:
    // What is the difference between the arrays? - in the first case there is an end line character

    return 0;
}
