/*
 * Create a function that takes an array as argument and it's length. Determine the right data types to do this.
 * This function should order the arguments in ascending order and return this in a new sorted array.
 *
 * Create a second function that takes 3 arguments. An array, it's length and a number it is searching for.
 * The function should return the index of the number when found or -1 if it's not part of the array.
 * IMPORTANT: this function expects a sorted array and uses the strategy we used when we play guess the number.
 *
 *
 * In the main function create an unsorted array filled with random numbers, Make it 50 long.
 * Try 2 scenarios:
 *    * In the first: You pick a random element in the unosrted array and check at which index it is after the array is sorted.
 *    * In the second: You pick a number You are sure is not in the array. Check whether the search function returns the right number.
 * Print out what You need to check these.
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int *bubble_sort(int *to_sort,int size);
int numberfinder(int *array,int size, int target);
void printer(int *array, int size);

int main()
{
    int size = 0;
    printf("enter the size of the array:  ");
    scanf("%d", &size);

    int to_sort[size];
    int *p_sorted;

    srand(time(0));

    // filling up array
    for (int i = 0; i < size; i++) {
        to_sort[i] = rand() % 10;
    }

    printer(to_sort, size);

    // bubble sort to_sort array, and save the return array with p_sorted pointer.
    p_sorted = bubble_sort(to_sort, size);

    printf("sorted array: \n");

    printer(p_sorted, size);

    // testing for -1
    int target = 15;
    printf("finding target %d, and it was found at: %d\n", target, numberfinder(p_sorted, size, target));

    // testing for first position found of target
    target = 9;
    printf("finding target %d, and it was found at: %d\n", target, numberfinder(p_sorted, size, target));

    return 0;
}

void printer(int *array, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d\n", array[i]);
    }
}

int *bubble_sort(int *to_sort, int size)
{
    static int sorted[50];

    int temp = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (to_sort[j] > to_sort[j + 1]) {
                temp = to_sort[j];
                to_sort[j] = to_sort[j + 1];
                to_sort[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        sorted[i] = to_sort[i];
    }
    return sorted;
}

int numberfinder(int *array, int size, int target)
{
    int position = -1;

    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            position = i;
            break;
        }
    }
    return position;
}
