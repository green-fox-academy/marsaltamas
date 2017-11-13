/*
 * Create a function that takes an array of characters and returns an array of integers each representing the
 * length of the given character array in the first array.
 * Say your input is this: {"Good", "Morning", "Vietnam"}
 * Your output should be this: {4, 7, 7}.
 * HINT: strings are terminated with a special character: '\0'.
 * So, "Good" as an array of characters would look like this: {'G', 'o', 'o', 'd', '\0'}.
 *
 * In the main function create code that demonstrates that Your function works appropriately.
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

void length_counter(char *string_array[], int int_array[], int size);
int *length_counter_w_return(char *string_array[], int int_array[], int size);

int main()
{
    char *string_array[] = {"Goodoo", "Morningu", "Vietnamu"};
    int int_array[3];
    int size = sizeof(int_array) / sizeof(int_array[0]);
    int *p_int_array = NULL;

    length_counter(string_array, int_array, size);

    for (int i = 0; i < size; i++) {
        printf("%s\n", string_array[i]);
        printf("int_array[%d]: %d\n", i, int_array[i]);
    }

    p_int_array = length_counter_w_return(string_array, int_array, size);

    for (int i = 0; i < size; i++) {
        printf("%s\n", string_array[i]);
        printf("p_int_array[%d]: %d\n", i, *p_int_array);
        p_int_array++;
    }

    return 0;
}

void length_counter(char *string_array[], int int_array[], int size)
{
    for (int i = 0; i < size; i++) {
        int_array[i] = strlen(string_array[i]);

    }
}

int *length_counter_w_return(char *string_array[], int int_array[], int size)
{
    static int *return_array[50];

    for (int i = 0; i < size; i++) {
        return_array[i] = strlen(string_array[i]);
    }

    return return_array;
}

