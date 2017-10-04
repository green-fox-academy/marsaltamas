#include <stdio.h>
#include <stdlib.h>

/*
write a program to find the largest number of three
*/

int main()
{
    int a = -1000;
    int b = -400;
     int c = -100;

    int largest = a;

    if (b > largest)
        largest = b;

    if (c > largest)
        largest = c;

    printf("The largest number is %d.", largest);


    return 0;
}
