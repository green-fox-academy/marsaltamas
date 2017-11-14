#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
using namespace std;

class Circle
{
    private:
        float radius;
    public:
        Circle(float radius);
        ~Circle();
        float get_radius();
        void set_radius(float radius);
        float get_circumference();
        float get_area();
};

#endif // CIRCLE_H
