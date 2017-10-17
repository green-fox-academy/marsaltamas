#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i_array[10] = {260, 259, 258, 257, 256, 255, 254, 253, 252, 251};
    unsigned char uc_array[10];

	//TODO: write a program, which copies the values from the given array to an unsigned char array
    //print out the elements of the unsigned char array, with the "%d" format specifier
    //what do you see?

    for (int i = 0; i < sizeof(i_array) / sizeof(i_array[0]); i++)  {

        i_array[i] = uc_array[i];
        printf("i_array[%d]: %c\n", i, i_array[i]);
        printf("uc_array[%d]: %c\n", i, uc_array[i]);
    }

    // same result as from the int array


    return 0;
}
