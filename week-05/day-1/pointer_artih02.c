/*
 * Create an array of integers. Make it 16 long. Fill it up with numbers as You wish. Print them out.
 *     * Iterate over it with a pointer so, that You only get to each _second_ element. Print out only these.
 *     * Iterate over it only touching each _fourth_ element. Print out only these.
 *     * Iterate over it only touching each _eighth_ element. Print out only these.
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#define SIZE 16

int main()
{
    int array[SIZE];
    int *p = array;

    srand(time(0));

    for (int i = 0; i < SIZE; i++) {
        *p = rand() % 100;
        p++;
    }

    p = p - SIZE;

/* ================ printing each element ================ */

    printf("printing every element:\n");
    int i = 0;
    while (i < SIZE) {
         printf("array[%d]: %d\n", i, *p);
         i++;
         p++;
    }


/* ================ printing ever 2nd element ================ */

    p = p - SIZE;
    printf("printing every 2nd element:\n");
    i = 0;
    while (i < SIZE) {
         printf("array[%d]: %d\n", i, *p);
         i+= 2;
         p+= 2;
    }

/* ================ printing ever 4th element ================ */

    p = p - SIZE;
    printf("printing every 4th element:\n");
    i = 0;
    while (i < SIZE) {
         printf("array[%d]: %d\n", i, *p);
         i+= 4;
         p+= 4;
    }

/* ================ printing ever 8th element ================ */

    p = p - SIZE;
    printf("printing every 8th element:\n");
    i = 0;
    while (i < SIZE) {
         printf("array[%d]: %d\n", i, *p);
         i+= 8;
         p+= 8;
    }

    return 0;
}
