#include <stdio.h>
#include <stdlib.h>
#include "gcd_header.h"

// create a function to find the greatest common divisor of two numbers (a and b)
// again the parameters value should be stored in a .h file
// use recursion

int gcd_rec(int bigger_num, int smaller_num);

int main()
{
    printf("%d", gcd_rec(BIGGER_NUM, SMALLER_NUM));

    return 0;
}

int gcd_rec(int bigger_num, int smaller_num)
{
    if (bigger_num % smaller_num == 0)
        return smaller_num;

    int temp = bigger_num % smaller_num;
    bigger_num = smaller_num;
    smaller_num = temp;

    return gcd_rec(bigger_num, smaller_num);
}
