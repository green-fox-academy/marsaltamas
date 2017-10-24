#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <dos.h>

// TODO:
// Create a struct that represents a House
// It should store:
//  - The address of the house
//  - The price in EUR
//  - The number of rooms
//  - The area of the house in square meters

typedef struct House {
    char adress[10];
    float price;
    int room_number;
    float area;
} House;

// print out a house
void house_printer(House house);

//returns a house with random value members
House house_builder(void);

// TODO:
// The market price of the houses is 400 EUR / square meters
// Create a function that takes a pointer to a house and decides if it's worth to buy
// (if the price is lower than the calculated price from it's area)

int worth_it(House *house);

// TODO:
// Create a function that takes an array of houses (and it's length), and counts the
// houses that are worth to buy.

int worth_it_ev_array(House *houses, int size);

// for seeding random generator with time
void delay(int number_of_ms);

int main()
{
    House house1 = house_builder();
    house_printer(house1);
    worth_it(&house1);

    House house[100];

    for (int i = 0; i < 5; i++) { // building 5 houses randomly
        house[i] = house_builder();
    }

    printf("number of houses worth it: %d\n", worth_it_ev_array(house, 5));

    return 0;
}

void house_printer(House house)
{
    printf("address: %s\n", house.adress);
    printf("price: %.2f\n", house.price);
    printf("number of rooms: %d\n", house.room_number);
    printf("area: %.2f\n", house.area);
}

House house_builder(void)
{
    srand(time(NULL));

    delay(1000);
    House house;

    strcpy(house.adress, "address");
    house.price = (float) (rand() % 1000) * 50;
    house.room_number = rand() % 10;
    house.area = (float) (rand() % 100);

    return house;
}

int worth_it(House *house)
{
    if (house->price / house->area < 400) {
        printf("Worth it.\n");
        return 1;
    }
    else {
        printf("Doesn't worth it.\n");
        return 0;
    }
}

int worth_it_ev_array(House houses[], int size)
{
    int quantity_worht_it = 0;

    for (int i = 0; i < size; i++) {
        if (worth_it(&houses[i]))
            quantity_worht_it++;
    }

    return quantity_worht_it;
}

void delay(int number_of_ms)
{
    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + number_of_ms);
}
