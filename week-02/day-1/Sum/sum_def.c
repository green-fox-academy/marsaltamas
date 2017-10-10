#include "sum_header.h"

int sum(int until)
{
    int result = 0;
    int temp = 0;

    for (int i = 0; i < until; i++) {
        printf("Enter %d number to add to result. Result currently is %d.\n", until, result);
        fflush(stdin);
        scanf("%d", &temp);
        printf("Your entered %d. %d + %d = %d.\n", temp, temp, result, result = temp + result);
        fflush(stdin);
    }

    return result;
}
