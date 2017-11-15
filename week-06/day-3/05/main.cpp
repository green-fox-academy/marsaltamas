// Create a Car class.
// Create the following private variables : age, kms_run, manufacturer, number_of_seats
// use proper variable types.
// Implement a method which has one parameter, and increases the kms_run variable by its parameter value.
// Implement a method which can add a person to a car, if the number of persons in the car reached
// the value of number of seats in the car it should tell you that 'The car is full!' or something like that.
// Inherit at least two car models and try out the methods you have created.

#include "car.h"
#include "lada.h"
#include "trabant.h"
#include <vector>

int main()
{
    Lada l(10, 45000, "Lada factory", 5);
    Trabant t(34, 2000, "Trabant factory", 4);

    cout << "Testing Lada: " << endl;
    cout << "Drived 55 000 kms, so instead of " << l.get_kms_run() << " run kms ";
    l.kms_run_since_last_time(55000);
    cout << "Lada has " << l.get_kms_run() << " kms run." << endl;

    for (int i = 1; i < 7; ++i) {
        cout << "Adding " << i << "th person: " << l.add_person();
    }

    cout << "===============" << endl;

    cout << "Testing Trabant: " << endl;
    cout << "Drived 10 000 kms, so instead of " << t.get_kms_run() << " run kms ";
    t.kms_run_since_last_time(10000);
    cout << "Trabant has " << t.get_kms_run() << " kms run." << endl;

    for (int i = 1; i < 7; ++i) {
        cout << "Adding " << i << "th person: " << t.add_person();
    }

    cout << "=============" << endl << "Printing a car pointer vector:" << endl;

    Trabant *t1 = new Trabant(1, 1, "trabant 1", 4);
    Trabant *t2 = new Trabant(1, 1, "trabant 2", 4);
    Trabant *t3 = new Trabant(1, 1, "trabant 3", 4);
    Lada *l1 = new Lada(1, 1, "lada 1", 4);

    vector<Car*> cars;

    cars.push_back(t1);
    cars.push_back(t2);
    cars.push_back(t3);
    cars.push_back(l1);

    for (unsigned int i = 0; i < cars.size(); ++i) {
        cout << cars.at(i)->get_manufacturer() << endl;
    }

    return 0;
}
