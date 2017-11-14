// Create a `Circle` class that takes it's radius as constructor parameter
// It should have a `get_circumference` method that returns it's circumference
// It should have a `get_area` method that returns it's area

#include <iostream>
#include "circle.h"
using namespace std;

int main()
{
    Circle circle(10);
    cout << "Circumference: " << circle.get_circumference() << endl;
    cout << "Area: " << circle.get_area() << endl;

    return 0;
}
