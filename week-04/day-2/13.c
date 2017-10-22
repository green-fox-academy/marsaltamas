#include <stdio.h>

int my_strlen(char *string);

int main()
{
	char my_string[50] = "";

	//TODO: implement your own strlen function.

	printf("using own func: %d\n", my_strlen(my_string));
    printf("using strlen func: %d", strlen(my_string));

	return 0;
}

int my_strlen(char *string)
{
    int i = 0;
    int count = 0;

    while (string[count] != '\0') {
        count++;
    }

    return count;
}
