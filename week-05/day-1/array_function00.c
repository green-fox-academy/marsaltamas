/*
 * Create a function that takes an array of integers as an argument (a pointer) and it's length as an unsigned integer.
 * The function should sort the elements of the array in ascending order.
 *
 * Print it out before and after to be able to check whether it works as supposed.
 */

 #include <stdlib.h>
 #include <stdio.h>
 #include <time.h>

void bubble_sort(int *to_sort, unsigned int size);

 int main()
 {
    unsigned int size = 0;
    printf("enter the size of the array:  ");
    scanf("%d", &size);

    int to_sort[size];
    int temp = 0;

    srand(time(0));

    for (int i = 0; i < size; i++) {
        to_sort[i] = rand() % 10;
    }

    for (int i = 0; i < size; i++) {
        printf("%d\n", to_sort[i]);
    }

    bubble_sort(to_sort, size);

    printf("sorted array: \n");

    for (int i = 0; i < size; i++) {
        printf("%d\n", to_sort[i]);
    }

    return 0;
 }

void bubble_sort(int *to_sort, unsigned int size)
{
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
}
