// create a function called `factorio`
// that returns it's input's factorial with and without recursion
// again the parameters value should be stored in a .h file
#include <stdlib.h>
#include "factorio_header.h"

void factorio (int n);
int factorio_rec (int n);

int main()
{
    factorio(TO_FACTOR);
    printf("factorio of %d using recursion is %d", TO_FACTOR, factorio_rec(TO_FACTOR));

    return 0;
}

void factorio(int n)
{
    int result = 1;

    for (int i = 1; i <= n; i++) {
        result = result * i;
    }

    printf("factorio of %d is %d\n", n, result);

    return result;
}

int factorio_rec(int n)
{
    if (n == 1)
        return 1;
    else
        return n*factorio_rec(n - 1);
}

