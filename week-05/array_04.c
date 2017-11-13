/*
 * Create 9 arrays of characters, each should contain a word.
 * Let it be this: The Quick brown Dog jumps over the Lazy Fox.
 * Create an array of 9 pointers of chractrer type.
 * Make it so, that each pointer points to one of the words. Meaning to one of the original arrays You just created.
 * So You'll have a pointer pointing to each of these original arrays in an array of pointers.
 * Print them out, each in a new line using this array of pointers.
 * Now make it so, that the Fox is Green and he jumps over the lazy dog.
 * Use the existing arrays to achive this.
 * Print it out again.
 */

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main()
{
    char *array_The = "The";
    char *array_Quick = "Quick";
    char *array_brown = "brown";
    char *array_Dog= "Dog";
    char *array_jumps = "jumps";
    char *array_over = "over";
    char *array_the = "the";
    char *array_Lazy = "Lazy";
    char *array_Fox = "Fox";

    char *p_array_The = array_The;
    char *p_array_Quick = array_Quick;
    char *p_array_brown = array_brown;
    char *p_array_Dog= array_Dog;
    char *p_array_jumps = array_jumps;
    char *p_array_over = array_over;
    char *p_array_the = array_the;
    char *p_array_Lazy = array_Lazy;
    char *p_array_Fox = array_Fox;

    char *array[] = {p_array_The, p_array_Quick, p_array_brown, p_array_Dog, p_array_jumps, p_array_over, p_array_the, p_array_Lazy, p_array_Fox};

    for (int i = 0; i < 9; i++) {
        printf("%s\n", array[i]);
    }
    printf("\n");

    array[2] = "Green";
    array[3] = array_Fox;
    array[8] = array_Dog;

    for (int i = 0; i < 9; i++) {
        printf("%s\n", array[i]);
    }

    return 0;
}
