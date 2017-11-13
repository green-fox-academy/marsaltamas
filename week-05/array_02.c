/*
 * Create an array of 12 integers. Fill it with random numbers.
 * Sort them in ascending order using bubble sort. -- Google it if You don't know it. (It's easy)
 * Print out the numbers before and after the sorting.
 */

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void array_printer(int array[], int size);

int main()
{
    int array_12[12];
    int size = 12;
    int temp = 0;

    srand(time(0));

    for (int i = 0; i < size; i++) {
        array_12[i] = rand() % 10;
    }

    array_printer(array_12, size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array_12[j] > array_12[j + 1]) {
                temp = array_12[j];
                array_12[j] = array_12[j + 1];
                array_12[j + 1] = temp;
            }
        }
    }

    printf("\n");
    array_printer(array_12, size);

    return 0;
}

void array_printer(int array[], int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d | ", array[i]);
    }
}
