
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
    int from = 2;
    int to = 100;
    int prime_counter = 0;
    int prime = 0;

    if (from == 1)
        printf("2 is a prime number.\n");

    for (int number = from + 1; number < to ; number++){

        if(prime){
        prime_counter++;
        printf("%d is a prime number.\n", number-1);
        prime = 0;
}


        for (int i = 2; i < number; i++){



        if(number % i == 0 ) {
            prime = 0;
            break;
          //  break;

        }
        prime = 1;

    }

    }

    if (from == 1)
   printf("Number of primes %d.", prime_counter+1);
    else
         printf("Number of primes %d.", prime_counter);

   return 0;

}
