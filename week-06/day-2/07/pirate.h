// create a pirate class
// it should have 2 methods
// drink_rum()
// hows_goin_mate()
// if the drink_rum was called at least 5 times:
// hows_goin_mate should return "Arrrr!"
// "Nothin'" otherwise
#ifndef PIRATE_H
#define PIRATE_H

using namespace std;
#include <string>
#include <iostream>


class Pirate
{
    private:
        int rum_drank;
    public:
        Pirate();
        ~Pirate();
        void drink_rum();
        string hows_goin_mate();
};

#endif // PIRATE_H
