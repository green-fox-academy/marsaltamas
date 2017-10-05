#include <stdio.h>
#include <stdlib.h>

/*
write a program that decides which number is bigger
use switch-statement
*/

int main()
{
    int num1;
    int num2;

    num1 = 85;
    num2 = 85;

    int result;

    if (num1 > num2)
        result = 1;
    else if (num1 < num2)
        result = 2;
    else
        result = 3;


    switch  (result){
    case 1 :
        printf("num1 = %5d is bigger than\nnum2 = %5d.", num1, num2);
        break;
    case 2 :
        printf("num2 = %5d is bigger than\nnum1 = %5d.", num2, num1);
        break;
    default :
        printf("num1 = %5d equals\nnum2 = %5d.", num1, num2);

    }

    return 0;
}
