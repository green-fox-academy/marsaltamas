#include <stdio.h>

/*
Create a program which prints out oll the prime numbers
aslo add a feature where you can tell the from - to limits
for example :
from = 11;
to = 34;
output :
13, 17, 19, 23, 29, 31 , this is 6 prime numbers
*/

int main()
{
    int from = 11;
    int to = 34;
    int prime_counter = 0;
    // this checks if the given number is prime
    int prime = 0;

    // conditions for ranges and number of 2
    if (from == 1 && to > 1) {

        printf("2 is a prime number.\n");
        prime_counter++;
    }

    for (int number = from + 1; number < to ; number++){

        //  if the previous number was prime (prime = 1), counter increased, message printed, and prime set back to null
        if(prime) {
        prime_counter++;
        printf("%d is a prime number.\n", number-1);
        prime = 0;
        }

        for (int i = 2; i < number; i++){


            // if a divisor is found for number i, prime is set to null and loop is quited,
            if(number % i == 0 ) {
                    prime = 0;
                    break;

            }

        // if divisor not found, prime is set to 1 to increment prime_counter at the beginning of the loop
        prime = 1;
        }
    }

         printf("Number of primes %d.", prime_counter);

   return 0;

}
