# include <stdlib.h>
# include <math.h>

void power_function (int x, int y)
{

        char * mess = "sorry, i take only integers as power.\n";



    int result = 1;

    for (int i = 0; i < y; i++) {


        result = result * x;

    }

        if (x == 0)
            printf("valami/n");
        else
            printf("%d", result);

}

int main()
{

    int base = 1;
    int power = 3;
    double db_base = (double) base;
    double db_power = (double) power;
    int displ = 0;

    displ = power_function(base, power);


    printf("result of own power function: %d\n", displ);
    printf("check nr with inbuilt pow() function: %f", pow(base, power));

    return 0;
}
