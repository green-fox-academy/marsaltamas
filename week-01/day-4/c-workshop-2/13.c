#include <stdio.h>

/*
create a program which converts the fahrenheit to celsius
the output should look like this:
Fahrenheit       Celsius
  0               -17.8
 20                -6.7
 40                 4.4
 60                15.6
...
print out at least 10 lines
*/

int main() {

    float fahrenheit;
    float celsius;


   for (int i = 0; i < 101; i+=10) {

    fahrenheit = i;
    celsius = ((fahrenheit - 32) / 1.8);

    printf("Fahrenheit = %.2f\tCelsius = %.2f\n", fahrenheit, celsius);

   }


	return 0;
}
