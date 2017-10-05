#include <stdio.h>
int main()

/*
create a program which draws a diamond, like this:
      *
    * * *
  * * * * *
* * * * * * *
* * * * * * *
  * * * * *
    * * *
      *
*/

{

    int i = 1;
    for (i; i<5; i++){

        for (int j = 1; j<4+i; j++){

                if((j<8-(7/2+i)) || (j>((7/2+i))))
                         printf("%c", ' ');
                else
                        printf("%c", '*');

                printf("%c", ' ');


        }
        printf("\n");

    }

    int x = 4;
    for (x; x>0; x--){

            for (int j = 2 + i; j>0; j--){

                    if((j<8-(7/2+x)) || (j>((7/2+x))))
                             printf("%c", ' ');
                    else
                            printf("%c", '*');

                    printf("%c", ' ');

            }
            printf("\n");

    }

    return 0;

}
