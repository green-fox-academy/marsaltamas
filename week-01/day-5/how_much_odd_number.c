#include <stdio.h>
#include <stdlib.h>

//how much odd numbers are between 179 & 371
//you should be able to change the limits, like from 10 to 234
//and the program should print out the odd numbers between those two numbers
//example from 11 to 27 the program should print out:
// 13, 15, 17, 19, 21, 23, 25 this is 7 odd number between 11 and 27

int main()
{

    int start = 10;
    int end = 30;
    int counter_odd = 0;

    for (int i = start+1; i < end; i++){

        if (i % 2){

            if (counter_odd == 0)
                printf(" %d", i);
            else
                printf(", %d", i);

            counter_odd++;

        }

    }

    printf(" This is %d odd number between %d and %d.", counter_odd, start, end);


	return 0;
}
