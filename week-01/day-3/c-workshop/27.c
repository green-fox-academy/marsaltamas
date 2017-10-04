#include <stdio.h>
#include <stdlib.h>

/*
swap the values of the to number
print out first the original values then print out the swaped values
but this time use bitwise operators only
*/

int main()
{
    int x = 1345;
    int y = -40;


    printf("original x was: %d\n", x);
    printf("original y was: %d\n", y);


    int a = x ^ 0;


    x = y ^ 0;
    y = a ^ 0;



    printf("After swapped x is: %d\n", x);
    printf("After swapped y is: %d\n", y);


    return 0;

}
