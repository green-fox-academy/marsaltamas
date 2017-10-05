#include <stdio.h>

int main() {
	// Write a program that prints the numbers from 1 to 100.
	// But for multiples of three print "Fizz" instead of the number
	// and for the multiples of five print "Buzz".
	// For numbers which are multiples of both three and five print "FizzBuzz".

	int a = 1;

	for (int i = 1; i <= 100; i++)
    {
         printf("for loop FizzBuzz  ");

        if ( i%3 == 0 && i%5 == 0 )
            printf("FizzBuzz\n");
        else if ( i%3 == 0 )
            printf("Fizz\n");
        else if ( i%5 == 0 )
            printf("Buzz\n");
        else
            printf("i = %d\n", i);

    }

    printf("\n\n");


    while (a <=100)
    {
        printf("while loop FizzBuzz  ");

        if ( a%3 == 0 && a%5 == 0 )
            printf("FizzBuzz\n");
        else if ( a%3 == 0 )
            printf("Fizz\n");
        else if ( a%5 == 0 )
            printf("Buzz\n");
        else
            printf("a = %d\n", a);

        a++;

    }

    printf("\n\n");
    a = 1;

    do
    {
        printf("do-while loop FizzBuzz  ");

        if ( a%3 == 0 && a%5 == 0 )
            printf("FizzBuzz\n");
        else if ( a%3 == 0 )
            printf("Fizz\n");
        else if ( a%5 == 0 )
            printf("Buzz\n");
        else
            printf("a = %d\n", a);

        a++;

    }while (a <=100);

	return 0;
}
