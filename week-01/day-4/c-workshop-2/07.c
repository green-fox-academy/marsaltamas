#include <stdio.h>
#include <stdlib.h>

/*
create a simple program which checks if the num is odd or even
*/

int main()
{
    int num;
    num = -2;

    int result = num % 2;

    if (num == 0){
        printf("num = %d.", num);
    }
    else{
    switch (result){
    case 0 :
        printf("num = %d is even.", num);
        break;
    case 1 :
        printf("num = %d is odd.", num);
        break;
    default :
        printf("def");
    }
    }

    return 0;
}
