#include "car.h"

Car::Car(int age, float kms_run, string manufacturer, int number_of_seats)
{
    this->age = age;
    this->kms_run = kms_run;
    this->manufacturer = manufacturer;
    this->number_of_seats = number_of_seats;
    passangers = 0;
}

void Car::kms_run_since_last_time(float kms_to_add)
{
    kms_run+= kms_to_add;
}

string Car::add_person()
{
    if (passangers == number_of_seats) {
        return "Car is full.\n";
    } else {
        passangers++;
        return "Person added.\n";
    }
}

int Car::get_seats()
{
    return number_of_seats;
}

float Car::get_kms_run()
{
    return kms_run;
}
