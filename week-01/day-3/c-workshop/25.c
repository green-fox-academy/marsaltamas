#include <stdio.h>
#include <stdlib.h>

/*
write a program to find the largest number of three
*/

int main()
{
    int a = -1000;
    int b = 400;
    int c = 1100;

    int largest = a;

    if (b > largest)
        largest = b;

    if (c > largest)
        largest = c;

    printf("The largest number is %d.\n", largest);


    if ((a > b) && (a > c))
        largest = a;
    else if ((b > a) && (b > c))
        largest = b;
    else
        largest = c;

    printf("The largest number using if-else if-else is %d.\n", largest);


    return 0;
}
