/*
 * Create an array of integers. Make it 10 long at least. Fill it up with numbers - random or toherwise - as You wish.
 * Iterate over this array using a pointer. Print out it's elements.
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

int main()
{
    int array[10];
    int *p = array;

    srand(time(0));

    for (int i = 0; i < 10; i++) {
        *p = rand() % 100;
        p++;
    }

    p = p - 10;

    int i = 0;
    while (i < 10) {
         printf("array[%d]: %d\n", i, *p);
         i++;
         p++;
    }

    return 0;
}
