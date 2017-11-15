#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape
{
    public:
        Circle(float radius);
        float get_radius();
        float get_area();
        virtual float how_much_to_paint(float area, float paint_price_per_sqm);

    protected:

    private:
        float radius;
        float calc_area();
};

#endif // CIRCLE_H
