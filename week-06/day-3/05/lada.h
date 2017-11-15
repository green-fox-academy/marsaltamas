#ifndef LADA_H
#define LADA_H

#include "car.h"


class Lada : public Car
{
    public:
        Lada(int age, float kms_run, string manufacturer, int number_of_seats)
        :Car(age, kms_run, manufacturer, number_of_seats){};
        string get_manufacturer();
};

#endif // LADA_H
