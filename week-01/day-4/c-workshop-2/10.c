#include <stdio.h>
#include <stdlib.h>

/*
write a simple program which can help you decide is it hot enough to turn on the AC or not

for example if temperature 20 or less the output is :
it is too cold for the AC

or, the temperature is between 21-24:
it is up to you to turn on the AC
...
*/

int main()
{
    int temperature;
    temperature = 25;

    int result;

    if (temperature <= 20)
        result = 1;
    else if (temperature >20 && temperature < 25)
        result = 2;
    else
        result = 3;

    switch (result){
    case 1 :
        printf("Temperature is %d. It is too cold for the AC.", temperature);
        break;
    case 2 :
        printf("Temperature is %d. It is up to you.", temperature);
        break;
    default :
        printf("Temperature is %d. It is too hot, AC turned on.", temperature);

    }

    return 0;
}
