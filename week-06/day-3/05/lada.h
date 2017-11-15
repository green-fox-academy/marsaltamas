#ifndef LADA_H
#define LADA_H

#include "car.h"


class Lada : public Car
{
    public:
        Lada(int age, float kms_run, string manufacturer, int number_of_seats);
        void kms_run_since_last_time(float kms_to_add);
        string add_person();
};

#endif // LADA_H
