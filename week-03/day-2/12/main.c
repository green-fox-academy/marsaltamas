#include <stdio.h>
#include <string.h>
int main ()
{
	char string[55] = "This is a string for testing";
	char to_find[5] = "i";
	char *p;

	//TODO: write a program, which lists all position where character 'i' is found

	// using for loop w/manual search
	for (int i = 0; i < strlen(string); i++) {

        if (string[i] == 'i')
            printf("Own \"function\": string[%d] is i.\n", i);
	}

	p = strpbrk(string, to_find);

	while (p != 0) {
        printf("strpbrk(): position was [%d]\n", p - string);
        p = strpbrk(p + 1, to_find);
	}

	return 0;
}
