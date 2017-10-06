#include <stdio.h>

/*
Write a program that prints the numbers from 1 to 100.
But for multiples of three print "Fizz" instead of the number
and for the multiples of five print "Buzz".
For numbers which are multiples of both three and five print "FizzBuzz".
But this time, use switch
*/

int main() {

    int a = 1;
    int result;

	for (int i = 1; i <= 100; i++) {
         printf("for loop FizzBuzz  ");

        if (i%3 == 0 && i%5 == 0)
            result = 1;
        else if (i%3 == 0)
           result = 2;
        else if (i%5 == 0)
            result = 3;
        else
            result = 4;


        switch (result) {
        case 1 :
            printf("FizzBuzz\n");
            break;
        case 2 :
            printf("Fizz\n");
            break;
        case 3 :
            printf("Buzz\n");
            break;
        default :
            printf("i = %d\n", i);


        }

    }



    return 0;
}
