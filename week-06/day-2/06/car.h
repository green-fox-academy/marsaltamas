// Create a class called "Car"
// It should have a "type" property that stores the car's type in a string eg: "Mazda"
// It should have a "km" property that stores how many kilometers it have run
// The km and the type property should be a parameter in the constructor
// It should have a method called "run" that takes a number and increments the "km" property by it
#ifndef CAR_H
#define CAR_H

using namespace std;
#include <string>
#include <iostream>

class Car
{
    private:
        string type;
        int kms_run;
    public:
        /** Default constructor */
        Car(string type, int kms_run);
        /** Default destructor */
        ~Car();
        int get_kms_run();
        void set_kms_run(int kms_run);
        void run(int kms_to_add);
};

#endif // CAR_H
