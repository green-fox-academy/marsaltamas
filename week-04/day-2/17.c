#include <stdio.h>
#define MAX_CHARS 255 // Maximum characters allowed

char most_frequent_char_finder(
    char *array, //in
    int size, //in
    int *p_occurance_of_most_frequent // out
    );

int main()
{
    //TODO: write a function which finds the maximum occurrence of a character in a given string.
    //return with the most frequent character
    //the number of occurrence should be an output parameter

    int highest_occurrence = 0;
    int *p_higthest_occurrence = &highest_occurrence;

    char str[] = "d is the dddmost freqdddduent eleddddddmedddddddtddddd.ddd";

    printf("most frequent char was %c\n", most_frequent_char_finder(str, sizeof(str) / sizeof(str[0]), p_higthest_occurrence));
    printf("num of occurrences of most frequent char was %d\n", *p_higthest_occurrence);

    return 0;
}

char most_frequent_char_finder(char *array, int size, int *p_occurance_of_most_frequent)
{
    char most_frequent = 0;
    int occurance = 0;
    int largest_occurance = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (array[i] == array[j]) {
                occurance++;
            }
            if (occurance > largest_occurance) {
                most_frequent = array[i];
                largest_occurance = occurance;
            }
        }
        occurance = 0;
    }
    *p_occurance_of_most_frequent = largest_occurance;
    return most_frequent;
}
