#include "house.h"

House::House(string address, unsigned int area)
{
    this->address = address;
    this->area = area;
}

unsigned int House::get_price(unsigned int area)
{
    return this-> area * 400;
}

unsigned int House::get_area()
{
    return this->area;
}
