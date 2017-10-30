/*
 * Create an array of 5 integers, fill it with random numbers.
 * Create an other of 7 integers.
 * Copy the contents of the first array into the second one in a way,
 * that the first and the last numbers of the second array are both 42,
 * and it contains all the elements of the first array.
 */

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void array_printer(int array[], int size);

int main()
{
    int array_5[5];
    int array_7[7];
    int temp = 0;

    srand(time(0));

    for (int i = 0; i < 5; i++) {
        array_5[i] = rand();
    }

    array_printer(array_5, 5);

    for (int i = 0; i < 7; i++) {
        if (i == 0 || i == 6)
            array_7[i] = 42;
        else
            array_7[i] = array_5 [i - 1];
    }

    printf("\n");

    array_printer(array_7, 7);

    return 0;
}

void array_printer(int array[], int size)
{
        for (int i = 0; i < size; i++) {
        printf("%d | ", array[i]);
    }
}
