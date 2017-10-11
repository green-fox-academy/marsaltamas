# include <stdlib.h>
# include <math.h>

// a function returning the result if we raise an integer to a base integer
int power_function (int x, int y);

int main()
{
    int base = 5;
    int power = 3;
    double base_d = (double) base;
    double power_d = (double) power;

    printf("The #%d power of %d is %d.\n", power, base,  power_function(base, power));
    printf("Checking result with inbuilt pow() function: %.0f.", pow(base_d, power_d));

    return 0;
}

int power_function (int x, int y)
{
    int result = 1;

    for (int i = 0; i < y; i++) {
        result = result * x;
    }

    return result;
}
