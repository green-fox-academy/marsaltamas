#include "circle.h"

Circle::Circle(float radius)
{
    this->radius = radius;
    cout << "You have created a circle with radius of " << this->radius << endl;
}

Circle::~Circle()
{
    cout << "Circles are closed here.";
}

float Circle::get_radius()
{
    return this->radius;
}

void Circle::set_radius(float radius)
{
    this->radius = radius;
}

float Circle::get_circumference()
{
    return 3.14 * radius * 2;
}

float Circle::get_area()
{
    return 3.14 * radius * radius;
}
