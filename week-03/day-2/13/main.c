#include <stdio.h>
#include <string.h>

int main ()
{
	char str[] = "This is a samp   le string";
    char *first, *last;

	//TODO: write a program which prints out the distance between the first and last occurrence of character 's'

	first = strchr(str, 's');
	last = strrchr(str, 's');

	printf("first occurrence was: %d\nlast occurrence was %d\ndistance: %d", first - str, last - str, (last - str) - (first - str));

    return 0;
}
