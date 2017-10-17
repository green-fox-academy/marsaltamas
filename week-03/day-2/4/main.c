#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	float val = 0;
	char str[5];
	strcpy(str, ".14");

	//TODO: print out the value of pi, first as a string, then a float value.

	printf("PI as string: %s\n", str);

	val = strtof(str, NULL);
	printf("PI as float %.3f\n", val);

	return(0);
}
