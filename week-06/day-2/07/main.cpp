// create a pirate class
// it should have 2 methods
// drink_rum()
// hows_goin_mate()
// if the drink_rum was called at least 5 times:
// hows_goin_mate should return "Arrrr!"
// "Nothin'" otherwise
#include "pirate.h"

int main()
{
    Pirate pirate;
    pirate.drink_rum();
    cout << pirate.hows_goin_mate();
    pirate.drink_rum();
    cout << pirate.hows_goin_mate();
    pirate.drink_rum();
    cout << pirate.hows_goin_mate();
    pirate.drink_rum();
    cout << pirate.hows_goin_mate();
    pirate.drink_rum();
    cout << pirate.hows_goin_mate();

    return 0;
}
