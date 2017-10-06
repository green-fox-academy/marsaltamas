#include <stdio.h>

/*
modify the previous program to print the table reverse order
for example:
Fahrenheit       Celsius
300               148.9
280               137.8
260               126.7
240               115.6
...
print out at least 10 lines
*/

int main() {


    float fahrenheit;
    float celsius;


   for (int i = 110; i > 0; i-=10) {

    fahrenheit = i;
    celsius = ((fahrenheit - 32) / 1.8);

    printf("Fahrenheit = %.2f\tCelsius = %.2f\n", fahrenheit, celsius);

   }


	return 0;
}
