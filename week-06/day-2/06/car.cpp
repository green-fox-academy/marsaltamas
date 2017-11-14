#include "car.h"

Car::Car(string type, int kms_run)
{
    this->type = type;
    this->kms_run = kms_run;
}

Car::~Car()
{
    cout << "Driver been stopped for speeding.";
}

int Car::get_kms_run()
{
    return kms_run;
}

void Car::set_kms_run(int kms_run)
{
    this->kms_run = kms_run;
}

void Car::run(int kms_to_add)
{
    kms_run+= kms_to_add;
}
