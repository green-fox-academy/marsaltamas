#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
using namespace std;

class Human
{
    public:
        Human();
        virtual void travel()
        {
             cout << "Human is walking." << endl;
        }
};

#endif // HUMAN_H
