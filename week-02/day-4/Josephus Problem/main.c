#include <stdio.h>
#include <stdlib.h>

// for checking results: http://webspace.ship.edu/deensley/mathdl/Joseph.html

int main()
{
   int n_th = 7; // n_th person to be eliminated
   int participants = 150;



   int arr[1000];

   //loading array from 1 with flags: 1 = alive, 0 = dead
   for (int i = 1; i <= participants; i++) {

        arr[i] = 1;
   }

   //printer
    for (int i = 1; i <= participants; i++) {

        printf("arr[%d] = %d\n", i, arr[i]);
   }


   int alive_counter = 0;
   int n_th_counter = 1;

   do {

    alive_counter = 0;

    for (int j = 1; j <= participants; j++) {

        if (n_th_counter != n_th && arr[j]) {
            n_th_counter++;
            alive_counter++;
        } else if (n_th_counter == n_th && arr[j]){
            arr[j] = 0;
            n_th_counter = 1;
        }
    }
   } while (alive_counter != 1);


   for (int k = 1; k <= participants; k++) {
        if (arr[k] == 1)
            printf("the one left alive was at position %d.", k);
           // break;
   }

    return 0;
}
