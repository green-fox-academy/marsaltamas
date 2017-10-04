#include <stdio.h>
#include <stdlib.h>

/*
swap the values of the to number
print out first the original values then print out the swaped values
*/

int main()
{
    int x = 59;
    int y = 20;

    printf("original x was: %d\n", x);
    printf("original y was: %d\n", y);


    int a = x;
    x = y;
    y = a;

    printf("After swapped x is: %d\n", x);
    printf("After swapped y is: %d\n", y);


    return 0;
}
