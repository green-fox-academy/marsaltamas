#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

//TODO: write a function which returns 485 as unsigned integer value
//put your return value in an integer variable in which you should have 229, and print it out
//try to figure out which type casting you should use


unsigned int fourhundred85(int input);

int main()
{

    uint16_t val = fourhundred85(270);

    printf("%d\n", val);

    return 0;
}

unsigned int fourhundred85(int input)
{
    return input;
}
