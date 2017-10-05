#include <stdio.h>
#include <stdlib.h>

/*
create a program which generates numbers from 0 to 100
for each number write if the number is odd or even (don't print out the numbers)
*/

int main()
{

    for (int i = 0; i <= 100; i++)
    {

        int result = i % 2;

        if (i == 0)
        {
            printf("It is null.\n");
        }
        else
        {
        switch (result){
        case 0 :
            printf("Even\n", i);
            break;
        case 1 :
            printf("Odd.\n", i);
            break;
        default :
            printf("def");
        }
        }

    }
    return 0;
}
