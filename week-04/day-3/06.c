#include <stdlib.h>
#include <stdio.h>

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

void house_printer(House house);
House house_bulider(char address[], float price, int rooms, float area);

// TODO:
// The market price of the houses is 400 EUR / square meters
// Create a function that takes a pointer to a house and decides if it's worth to buy
// (if the price is lower than the calculated price from it's area)

void worth_it(House *house);

// TODO:
// Create a function that takes an array of houses (and it's length), and counts the
// houses that are worth to buy.

int main()
{
    House house1 = house_bulider("budapest", 651, 3, 1);
    house_printer(house1);
    worth_it(&house1);
    return 0;
}

void house_printer(House house)
{
    printf("address: %s\n", house.adress);
    printf("price: %.2f\n", house.price);
    printf("number of rooms: %d\n", house.room_number);
    printf("area: %f\n", house.area);
}

House house_bulider(char address[], float price, int rooms, float area)
{
    House house;
    strcpy(house.adress, address);
    house.price = price;
    house.room_number = rooms;
    house.area = area;

    return house;
}

void worth_it(House *house)
{
    if (house->price / house->area < 400)
        printf("Worth it.\n");
    else
        printf("Doesn't worth it.\n");
}
