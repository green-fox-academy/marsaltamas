#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int a = 8;
    char buffer[20];
    //char str_to_bin[100];

    //TODO: make an integer to string conversion with itoa(), first in binary, then decimal format
    // Store the string in buffer

    itoa(a, buffer, 10);
    printf("int to string in dec format: %s\n", buffer);

    itoa(a, buffer, 2);
    printf("int to string in bin format: %s\n", buffer);

    return 0;
}
