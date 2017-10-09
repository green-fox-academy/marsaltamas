#include <stdlib.h>
#include <stdio.h>
#include "func_decl.h"

/*
Write a program where you have five functions
first the program should ask for an integer, then
these functions should do various mathematical operations on a given integer
last but not least there should be a variable which counts how many operations
have been done on the given integer
*/

int main()
    {
        get_input();

        printf("addition of 10: %d\n", add_10(input));
        printf("addition of 15: %d\n", add_15(input));
        printf("addition of 22: %d\n", add_22(input));
        printf("substraction of 22: %d\n", sub_22(input));
        printf("substraction of 34: %d\n", sub_34(input));

        printf("operations done: %d", op_done);

        return 0;
    }

