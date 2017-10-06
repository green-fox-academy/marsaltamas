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
    printf("printing pascal diamond using spaces\n");
    printf("++++++++++++++++++++++++++++++++++++\n\n");

    for (int i = 1; i < 5; i++){

        for (int j = 1; j< 4 + i; j++){

            if((j < 8 - (7 / 2 + i)) || (j > ((7 / 2 + i))))
                printf("%c", ' ');
            else
                printf("%c", '*');

                printf("%c", ' ');

        }
        printf("\n");
    }

    for (int i = 4; i>0; i--) {

        for (int j = 7; j > 0; j--) {

            if((j < 8 - (7 / 2 + i)) || (j > ((7 / 2 + i))))
                printf("%c", ' ');
            else
                printf("%c", '*');

                printf("%c", ' ');
        }
        printf("\n");
    }
    return 0;
}
