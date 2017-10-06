#include <stdio.h>
#include <math.h>

int main(){

    // prompting for user input

    int number_to_test = 0;

    printf("Enter a number to test, than press enter to check: ");
    scanf("%d", &number_to_test);

    int digits = 0;

    // temp holder used to test to number of digits
    int digit_test_num = number_to_test;
    // saving input value to compare with program result at the end
    int check_number = number_to_test;
    // this will store the result of the calculations
    int result = 0;
    // used to calculate and hold the sub result of each digit after pow-ing it
    int sub_result = 1;

    // counting digits using modulo

    while (digit_test_num > 0) {

        digit_test_num = (digit_test_num - (digit_test_num % 10)) / 10;
        digits++;
   }


    for (int i = 1; i <= digits; i++){

       int int_to_pow = number_to_test % 10;

       // setting number to pow

        sub_result = int_to_pow;

        // calculating pow of given digit

        for (int i = 1; i < digits; i++) {

            sub_result = sub_result * int_to_pow;
        }

        result = result + sub_result;

        //    pow function was used originally to test the number
        //    double double_to_pow = (double) int_to_pow;
        //    double digits_in_double = (double) digits;
        //    result =  result + pow ( double_to_pow, digits_in_double);

        //    updating the test number to know

        number_to_test = (number_to_test - number_to_test % 10) / 10;

   }

    if (result == check_number)
        printf("It is an Armstrong number.");
    else
        printf("It is not an Armstrong number.");


return 0;


}
