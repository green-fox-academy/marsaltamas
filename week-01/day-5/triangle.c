#include <stdio.h>

/*create a simple program which generates a triangle like this:
1
22
333
4444
55555
666666
7777777
if you change the rows variable the output should be different as well
*/
int main()
{
    int rows = 12;
    int int_to_count_digits_of = rows;
    int num_of_digits = 0;

    while (int_to_count_digits_of != 0){

        int_to_count_digits_of = (int_to_count_digits_of - (int_to_count_digits_of%10))/10;
        num_of_digits++;
    }

    printf("num of digits %d\n", num_of_digits);

    for (int i = 1; i <= rows; i++) {

        for (int j = 1; j <= i; j++) {

            printf("%*d", num_of_digits, i);
        }

        printf("\n");


    }

    return 0;
}
