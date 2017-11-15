// task 01
// Create a Shape class, inherit two derived class from it
// One should be Circle, and the other one is Triangle
// For each derived class, implement a calc_area() method
// which calculates the area of the shape and stores it inside
// the class (so it is a private method)

// task 02
// Continue the Shape exercise!
// Create getter methods for each values
// (for example: in a Triangle class you should be able to
// get: Height, Base and Area)

// task 03
// Still the shape exercise!
// Create public method called how_much_to_paint()
// which should get the area and the price of the paint as parameters
// It should return the costs of the painting

#include "shape.h"
#include "triangle.h"
#include "circle.h"

using namespace std;

int main()
{
    Shape *s;

    Triangle t(5, 10);
    Circle c(5);

    s = &t;

    t.print_data();

    cout << "Shape area (of triangle): " << s->get_area() << endl;
    cout << "Height of triangle with get_height: " << t.get_height() << endl;
    cout << "Base of triangle with get_base: " << t.get_base() << endl;

    s = &c;

    cout << "Shape area (of circle): " << s->get_area() << endl;
    cout << "Radius of the Circle with get_radius: " << c.get_radius() << endl;
    cout << "Area of the Circle: with get_area: " << c.get_area() << endl << endl;

    cout << "Triangle costs to paint: " << t.how_much_to_paint(t.get_area(), 2) << endl;
    cout << "Circle costs to paint: " << c.how_much_to_paint(c.get_area(), 2) << endl;

    return 0;
}
