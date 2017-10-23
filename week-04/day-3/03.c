#include <stdio.h>

enum CarType {VOLVO, TOYOTA, LAND_ROVER, TESLA};

typedef struct Car {
  enum CarType type;
  double km;
  double gas;
} Car_t;

// TODO:
// Write a function that takes a Car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

void car_printer(Car_t car);
void car_arr_printer(Car_t service_book[], int records);

int main()
{
    Car_t car1 = {VOLVO, 43, 50};
    Car_t car2 = {TOYOTA, 44, 51};
    Car_t car3 = {LAND_ROVER, 4545, 54};
    Car_t car4 = {TESLA, 422, 54};

    Car_t service_book[4] = {car1, car2, car3, car4};

    car_printer(car1);
    car_printer(car2);
    car_printer(car3);
    car_printer(car4);

    car_arr_printer(service_book, 4);

    return 0;
}

void car_printer(Car_t car)
{
    printf("type: %d\n", car.type);
    printf("km: %.2f\n", car.km);
    if (car.type != TESLA)
        printf("gas: %.2f\n", car.gas);
}

void car_arr_printer(Car_t service_book[], int records)
{
    printf("I am service book.\n");

    for (int i = 0; i < records; i++) {
        printf("type: %d\n", service_book[i].type);
        printf("km: %.2f\n", service_book[i].km);
        if (service_book[i].type != TESLA)
            printf("gas: %.2f\n", service_book[i].gas);
    }

}
