#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

using namespace std;

class Shape
{
    public:
        Shape();
        virtual float get_area() = 0;
        virtual float how_much_to_paint(float area, float paint_price_per_sqm) = 0;

    protected:
        virtual float area;

    private:
        virtual float calc_area() = 0;
};

#endif // SHAPE_H
