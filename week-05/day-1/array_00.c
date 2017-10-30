/*
 * Create an array of 5 integers.
 * Fill it with random integer numbers.
 * Print out the array elements in one line, divided by " | ".
 * Reverse the order of the numbers _in_the_array_ an print them out again.
 */

 #include <stdlib.h>
 #include <time.h>
 #include <stdio.h>

 void array_printer(int array[], int size);

 int main()
 {
    int array[5];
    int temp = 0;

    srand(time(0));

    for (int i = 0; i < 5; i++) {
        array[i] = rand();
    }

    array_printer(array, 5);

    for (int i = 0; i < 5 / 2; i++) {
        temp = array[i];
        array[i] = array[5 - i - 1];
        array[5 - i - 1] = temp;
    }

    printf("\n");

    array_printer(array, 5);

    return 0;
 }

void array_printer(int array[], int size)
{
        for (int i = 0; i < size; i++) {

        printf("%d | ", array[i]);
    }
}
