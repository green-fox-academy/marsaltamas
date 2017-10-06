#include <stdio.h>
#include <stdlib.h>

/*
Create a program which can tell how to pay an exact amount of money
for example 45670 Ft, is the amount (store this as an integer)
and the output should be:
2-20000Ft
1-5000Ft
1-500Ft
1-100Ft
1-50Ft
1-20Ft
*/

/*
Take care of the rounding (when giving back 5 coins):
1, 2 - 0 down
3, 4 - 5 up
6, 7 - 5 down
8, 9 - 0 up
*/

int main()
{
    int amount_of_money = 40201;
    int amount_of_money_left;

    //creating banknote values

    int note_20000 = 20000;
    int note_10000 = 10000;
    int note_5000 = 5000;
    int note_2000 = 2000;
    int note_1000 = 1000;
    int note_500 = 500;
    int note_200 = 200;
    int note_100 = 100;
    int note_50 = 50;
    int note_20 = 20;
    int note_10 = 10;
    int note_5 = 5;

    // setting up counters

    int total_paid = 0;

    // rounding

    int rounded = amount_of_money % 10;

    int to_substract;

    switch (rounded) {
    case 0 :
        to_substract = 0;
        break;
    case 1 :
        to_substract = -1;
        break;
    case 2 :
        to_substract = -2;
        break;
    case 3 :
        to_substract = 2;
        break;
    case 4 :
        to_substract = 1;
        break;
    case 5 :
        to_substract = 0;
        break;
    case 6 :
        to_substract = -1;
        break;
    case 7 :
        to_substract = -2;
        break;
    case 8 :
        to_substract = 2;
        break;
    case 9 :
        to_substract = 1;
        break;
    default :
        to_substract = 0;
    }

    amount_of_money_left = amount_of_money + to_substract;

    // printing user info

    printf("Bill total: %d.\n", amount_of_money);
    printf("Rounding:%d\n", to_substract);
    printf("Rounded sum is %d.\n", amount_of_money_left);

    // calculating notes to be used by checking which is the largest note can be used based on the remaining amount to be paid
    // than printing a message to the user
    // than calculating remaining amount to pay using

    do {

            if (amount_of_money_left >= note_20000) {
                total_paid = total_paid + ((amount_of_money_left/note_20000)*note_20000);
                printf("U paid %d Fts using %d pcs of HUF 20 000 bank note. Total paid so far: %d.\n",
                    (amount_of_money_left/note_20000)*note_20000, amount_of_money_left/note_20000, total_paid);
                amount_of_money_left  = amount_of_money_left%note_20000;
            } else if (amount_of_money_left >= note_10000) {
                total_paid = total_paid + ((amount_of_money_left/note_10000)*note_10000);
                printf("U paid %d Fts using %d pcs of HUF 10 000 bank note. Total paid so far: %d.\n",
                    (amount_of_money_left/note_10000)*note_10000, amount_of_money_left/note_10000, total_paid);
                amount_of_money_left  = amount_of_money_left%note_10000;
            } else if (amount_of_money_left >= note_5000) {
                total_paid = total_paid + ((amount_of_money_left/note_5000)*note_5000);
                printf("U paid %d Fts using %d pcs of HUF 5 000 bank note. Total paid so far: %d.\n",
                    (amount_of_money_left/note_5000)*note_5000, amount_of_money_left/note_5000, total_paid);
                amount_of_money_left  = amount_of_money_left%note_5000;
            } else if (amount_of_money_left >= note_2000) {
                total_paid = total_paid + ((amount_of_money_left/note_2000)*note_2000);
                printf("U paid %d Fts using %d pcs of HUF 2 000 bank note. Total paid so far: %d.\n",
                    (amount_of_money_left/note_2000)*note_2000, amount_of_money_left/note_2000, total_paid);
                amount_of_money_left  = amount_of_money_left%note_2000;
            } else if (amount_of_money_left >= note_1000) {
                total_paid = total_paid + ((amount_of_money_left/note_1000)*note_1000);
                printf("U paid %d Fts using %d pcs of HUF 1 000 bank note. Total paid so far: %d.\n",
                    (amount_of_money_left/note_1000)*note_1000, amount_of_money_left/note_1000, total_paid);
                amount_of_money_left  = amount_of_money_left%note_1000;
            } else if (amount_of_money_left >= note_500) {
                total_paid = total_paid + ((amount_of_money_left/note_500)*note_500);
                printf("U paid %d Fts using %d pcs of HUF 500 bank note. Total paid so far: %d.\n",
                    (amount_of_money_left/note_500)*note_500, amount_of_money_left/note_500, total_paid);
                amount_of_money_left  = amount_of_money_left%note_500;
            } else if (amount_of_money_left >= note_200) {
                total_paid = total_paid + ((amount_of_money_left/note_200)*note_200);
                printf("U paid %d Fts using %d pcs of HUF 200 bank note. Total paid so far: %d.\n",
                    (amount_of_money_left/note_200)*note_200, amount_of_money_left/note_200, total_paid);
                amount_of_money_left  = amount_of_money_left%note_200;
            } else if (amount_of_money_left >= note_100) {
                total_paid = total_paid + ((amount_of_money_left/note_100)*note_100);
                printf("U paid %d Fts using %d pcs of HUF 100 bank note. Total paid so far: %d.\n",
                    (amount_of_money_left/note_100)*note_100, amount_of_money_left/note_100, total_paid);
                amount_of_money_left  = amount_of_money_left%note_100;
            } else if (amount_of_money_left >= note_50) {
                total_paid = total_paid + ((amount_of_money_left/note_50)*note_50);
                printf("U paid %d Fts using %d pcs of HUF 50 bank note. Total paid so far: %d.\n",
                    (amount_of_money_left/note_50)*note_50, amount_of_money_left/note_50, total_paid);
                amount_of_money_left  = amount_of_money_left%note_50;
            } else if (amount_of_money_left >= note_20) {
                total_paid = total_paid + ((amount_of_money_left/note_20)*note_20);
                printf("U paid %d Fts using %d pcs of HUF 20 bank note. Total paid so far: %d.\n",
                    (amount_of_money_left/note_20)*note_20, amount_of_money_left/note_20, total_paid);
                amount_of_money_left  = amount_of_money_left%note_20;
            } else if (amount_of_money_left >= note_10) {
                total_paid = total_paid + ((amount_of_money_left/note_10)*note_10);
                printf("U paid %d Fts using %d pcs of HUF 10 bank note. Total paid so far: %d.\n",
                    (amount_of_money_left/note_10)*note_10, amount_of_money_left/note_10, total_paid);
                amount_of_money_left  = amount_of_money_left%note_10;
            } else if (amount_of_money_left >= note_5) {
                total_paid = total_paid + ((amount_of_money_left/note_5)*note_5);
                printf("U paid %d Fts using %d pcs of HUF 5 bank note. Total paid so far: %d.\n",
                    (amount_of_money_left/note_5)*note_5, amount_of_money_left/note_5, total_paid);
                amount_of_money_left = amount_of_money_left%note_5;
            }

    } while (total_paid !=  amount_of_money + to_substract);

    printf("See you next time!");

    return 0;
}
