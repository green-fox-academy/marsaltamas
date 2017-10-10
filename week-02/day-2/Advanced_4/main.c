#include <stdio.h>
#include <limits.h>

int main()
{
    //write a program which loads up fully a 50-sized integer array starting from 200 in descending order
    //but your array should contain elements which are divisible by 5 and 17
    //print out the array

    int my_array[50];
    int count = 0;

    for (int i = 200; i < INT_MAX; i++) {

        if (!(i % 85)) {
            my_array[count] = i;
            printf("#%d: Common divisor of 5 and 17 found at %d.\n", count, i);
            count++;
        }

        if (count == 50) {
            break;
        }
    }

    for (int i = 0; i < sizeof(my_array) / sizeof(my_array[0]); i++) {

        printf("Position #%d in my_array is %d\n", i, my_array[i]);
    }



    return 0;
}
