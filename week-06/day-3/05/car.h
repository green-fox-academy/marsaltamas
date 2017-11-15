// Create a Car class.
// Create the following private variables : age, kms_run, manufacturer, number_of_seats
// use proper variable types.
// Implement a method which has one parameter, and increases the kms_run variable by its parameter value.
// Implement a method which can add a person to a car, if the number of persons in the car reached
// the value of number of seats in the car it should tell you that 'The car is full!' or something like that.
// Inherit at least two car models and try out the methods you have created.
#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

using namespace std;

class Car
{
    private:
        int age;
        float kms_run;
        string manufacturer;
        int number_of_seats;

    public:
        Car();
        virtual void kms_run_since_last_time(float kms_to_add) = 0;
        virtual string add_person() = 0;
};

#endif // CAR_H
