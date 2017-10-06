#include <stdio.h>
#include <stdlib.h>

/*
find the greatest common divisor of the two given variables
use Euclid's algorithm, if you don't know it look it up on the internet
*/

int main()
{
    int x = 48;
    int y = 72;
    int gcd = 0;
    int temp = 0;

    if (x < y) {

        temp = x;
        x = y;
        y = temp;
    }

    if (x != 0 && y != 0){

        while (x != 0 || y != 0){
                if(x == 0){
                    gcd = y;
                    break;
                }
                if (y == 0){
                    gcd = x;
                    break;
                }

                temp = y;
                y =  x%(x/y * y);
                x = temp;
        }

        printf("greatest common divisor is %d\n", gcd);

    }else{
        printf("You can't divide by 0");
    }

    return 0;
}
