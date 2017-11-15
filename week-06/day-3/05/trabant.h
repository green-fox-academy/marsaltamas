#ifndef TRABANT_H
#define TRABANT_H

#include "car.h"


class Trabant : public Car
{
    public:
        Trabant(int age, float kms_run, string manufacturer, int number_of_seats)
        :Car(age, kms_run, manufacturer, number_of_seats){};
        string get_manufacturer();
};

#endif // TRABANT_H
