#include <stdio.h>
#include <stdlib.h>
#include "double_variable.h"

// create a function called `doubling` that doubles it's input parameter
// again the parameters value should be stored in a .h file

int doubling(int to_double);


int main()
{

    printf("%d doubled is %d\n", TO_DOUBLEMIN2, doubling(TO_DOUBLEMIN2));
    printf("%d doubled is %d\n", TO_DOUBLE0, doubling(TO_DOUBLE0));
    printf("%d doubled is %d\n", TO_DOUBLE2, doubling(TO_DOUBLE2));
    printf("%d doubled is %d\n", TO_DOUBLE4, doubling(TO_DOUBLE4));
    printf("%d doubled is %d\n", TO_DOUBLE8, doubling(TO_DOUBLE8));

    return 0;
}

int doubling(int to_double)
{
    return to_double * 2;
}
