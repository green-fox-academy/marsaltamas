#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main()
{
	int number_array[8] = {48, 59, 2, -8, 55, 56, 78, 12};

	//INT_MIN = number_array[0];

	//printf("%d\n", INT_MIN);

	int largest = 0;
	int second_largest = 0;

	for (int i = 0; i < 8; i++) {

	if (number_array[i] > second_largest && number_array[i] > largest) {

        largest = number_array[i];
	}
	else if (number_array[i] > second_largest) {

        second_largest = number_array[i];
	}
	}

	printf("largest: %d\n", largest);
	printf("seond largest: %d\n", second_largest);

	//TODO:
	// Write a C program to find the two largest element in an array using only 1 for loop
	// From <limits.h> use INT_MIN: this is the least integer

	return 0;
}
