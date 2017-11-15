#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"


class Triangle : public Shape
{
    public:
        Triangle(float base, float height);
        void print_data();
        float get_base();
        float get_height();
        float get_area();
        float how_much_to_paint(float area, float paint_price_per_sqm);

    private:
        float base;
        float height;
        float calc_area();
};

#endif // TRIANGLE_H
