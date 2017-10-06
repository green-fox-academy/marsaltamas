#include <stdio.h>
#include <math.h>

int main(){


int test_number = 10;
int digits = 0;
int number_to_count_digits = test_number;
int check_number = test_number;
double result = 0;

// counting digits using modulo



      while( number_to_count_digits > 0 ) {

    number_to_count_digits = (number_to_count_digits - (number_to_count_digits % 10))/10;
    digits++;
   }

   for (int i = 0; i <= digits; i++){

    int to_pow = test_number % 10;
    double double_to_pow = (double) to_pow;
    double digits_in_double = (double) digits;


    result =  result + pow ( double_to_pow, digits_in_double);
    test_number = (test_number - test_number % 10)/10;


   }

   if (result == check_number)
            printf( "It is an Armstrong number.");
    else
            printf( "It is not an Armstrong number.");


printf( "\nnumber of digits %d\n", digits);

printf( "%d\n", test_number);


test_number = (test_number - test_number % 10)/10;

printf( "%d\n", test_number);


test_number = (test_number - test_number % 10)/10;

printf( "%d\n", test_number);


test_number = (test_number - test_number % 10)/10;

printf( "%d\n", test_number);

return 0;


}
