#include "triangle.h"

Triangle::Triangle(float base, float height)
{
    this->base = base;
    this->height = height;
    this->area = calc_area();
}

void Triangle::print_data()
{
    cout << "Printing triangle's information: " << endl;
    cout << "Base: " << base << endl;
    cout << "Height: " << height << endl;
    cout << "Area: " << area << endl;
    cout << "===========" << endl << endl;
}

float Triangle::calc_area()
{
    return base * height / 2;
}

float Triangle::get_base()
{
    return base;
}

float Triangle::get_height()
{
    return height;
}

float Triangle::get_area()
{
    return area;
}

float Triangle::how_much_to_paint(float area, float paint_price_per_sqm)
{
    return area * paint_price_per_sqm;
}
