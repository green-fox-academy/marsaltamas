#include <stdlib.h>
#include "more_global_local.h"
#include <stdio.h>
#include <string.h>

//Tom, Mark and Jerry went to the supermarket
//help them decide what can they buy out of their money

//is there any local or global variables we did not use well?
//are we using functions correctly?


int main()
{
    can_they_buy_a_new_tv();
    can_they_make_a_cake();
    can_they_make_ham_and_eggs();

	return 0;
}

void can_they_buy_a_new_tv()
{
    int tv_price = 6950;
    int total_money = tom_money + mark_money + jerry_money;
    int money_left = total_money - tv_price;
    int money_needed = tv_price - total_money;

    if (total_money >= tv_price)
        printf("They can buy the tv and there will be left USD %d.\n", money_left);
    else
        printf("They need USD %d more to buy the tv.\n", money_needed);

    //if they can, the program should write out that how much
    //money they have after they bought the tv
    //if they can't tell, how much money they need to buy it
}

void can_they_make_a_cake()
{
    int milk = 200;
    int chocolate = 340;
    int flour = 75;
    int egg = 345;
    int sugar = 160;
    int salt = 90;
    int oven_shape = 330;
    int cream = 220;

    int total_money = tom_money + mark_money + jerry_money;
    int cake_price = milk + chocolate + flour + egg + sugar + salt + oven_shape + cream;

    if (total_money >= cake_price) {
        printf("Price of cake ingredients is USD %d\n", cake_price);
        printf("They can buy the cake and have to pay USD %.2f per person.\n", (float) cake_price / 3);
    }

    //if they can buy all these stuff calculate how much
    //each of them should pay to share the bill equally
}

void can_they_make_ham_and_eggs()
{
    int milk = 200;
    int egg = 345;
    int salt = 90;
    int ham = 450;
    int onion = 60;
    int spice = 25;

    int total_money = tom_money + mark_money + jerry_money;
    int grocery_price = milk + egg + salt + ham + onion + spice;

    if (total_money >= grocery_price) {
        printf("Price all grocery items they want to buy is USD %d\n", grocery_price);
        printf("They can buy all items form the grocery list and have to pay USD %.2f per person.\n", (float) grocery_price / 3);
    }

    //if they can buy all these stuff calculate how much
    //each of them should pay to share the bill equally
}




