#include <stdio.h>

int main()
{
    int number = 1234;
    int *p_number = &number;
    //TODO:
    // print the memory address of the variable

    printf("mem address of number: %p\n", &number);
    printf("content of p_number: %p\n", p_number);
    printf("value pointed by p_number: %d\n", *p_number);

    *p_number = 2222;

    printf("value of number: %d\n", number);
    printf("value pointed by p_number: %d\n", *p_number);

    return 0;
}
