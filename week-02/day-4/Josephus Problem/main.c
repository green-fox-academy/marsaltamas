#include <stdio.h>
#include <stdlib.h>

int main()
{
   int n_th = 2; // n_th person to be eliminated
   int participants = 41;

   int arr[1000];

   //loading array from 1 with flags: 0 = alive, 1 = dead
   for (int i = 1; i <= participants; i++) {

        arr[i] = 0;
   }

   int alive_counter = 2;
   int n_th_counter = 0;

   int i = 0; // iterator in do-while loop

   do {

    for (int j = 1; j <= participants; j++) {

        if (!arr[j])
            n_th_counter++;
        else
            alive_counter++;

        if (n_th_counter == n_th) {
            arr[j] = 1;
            n_th_counter = 0;
        }
    }

         if (alive_counter == 1)
            break;
        else
            alive_counter = 0;

   } while (alive_counter == 1);


   for (int k = 1; k <= participants; k++) {
        if (arr[k] == 0)
            printf("the one left alive was at position %d.", k);
           // break;
   }

    return 0;
}
