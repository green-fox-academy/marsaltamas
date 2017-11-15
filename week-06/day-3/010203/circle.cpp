#include "circle.h"

Circle::Circle(float radius)
{
    this->radius = radius;
    this->area = calc_area();
}

float Circle::calc_area()
{
    return 3.14 * radius * radius;
}

float Circle::get_radius()
{
    return radius;
}

float Circle::get_area()
{
    return area;
}

float Circle::how_much_to_paint(float area, float paint_price_per_sqm)
{
    return area * paint_price_per_sqm;
}
