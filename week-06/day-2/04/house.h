#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>
#include <string>

using namespace std;

class House
{
    private:
        string address;
        unsigned int area;
        unsigned int price;
    public:
        House(string address, unsigned int area);
        ~House();
        unsigned int get_price(unsigned int area);
        unsigned int get_area();
};

#endif // HOUSE_H
