#include <stdio.h>
#include <string.h>

//TODO:
// Print out the array character-by-character


int main()
{
    char my_name_array[] = "My Name ";

    for (int i = 0; i < strlen(my_name_array); i++)
    {
        printf("%c", my_name_array[i]);
    }

    printf("%s", my_name_array);
    puts(my_name_array);

    return 0;
}
