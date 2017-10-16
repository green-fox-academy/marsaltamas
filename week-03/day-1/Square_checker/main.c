#include <stdio.h>
#include <math.h>

// This program should work correctly with the following input: 20, 400
// first case compiler optimizes out pow, so pow is not actually called
// when calling pow, the actual double return result is rounded down when represented as in int, so i used round() function.
// scanf reads double with lf placeholder

int main()
{
//	int number, result;
//	printf("Please enter a number: ");
//	fflush(stdin);
//	scanf("%d", &number);
//
//	printf("Please enter the square of that number: ");
//	fflush(stdin);
//	scanf("%d", &result);
//
//	if ( round(pow(number, 2)) ==  result)
//		printf(":)\n");
//	else
//		printf(":(\n");

    // double variables and scanf used with lf scan
    double numberd, resultd;
	printf("Please enter a number: ");
	fflush(stdin);
	scanf("%lf", &numberd);

	printf("Please enter the square of that number: ");
	fflush(stdin);
	scanf("%lf", &resultd);

	if ( round(pow(numberd, 2)) ==  resultd)
		printf(":)\n");
	else
		printf(":(\n");

	return 0;
}
