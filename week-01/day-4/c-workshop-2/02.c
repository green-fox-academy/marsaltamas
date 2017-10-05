#include <stdio.h>
#include <stdlib.h>

/*
write a program to check whether a given number is positive or negative
*/

int main()
{
    int a = 0;

    if (a < 0)
        printf("a = %d is negative", a);
    else if (a > 0)
        printf("a = %d is positive", a);
    else
        printf("a = %d", a);

    return 0;
}
