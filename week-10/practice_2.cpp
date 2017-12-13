#include <iostream>
#include <string>

using namespace std;

class Pirate {
    public:
        Pirate()
        {
            rums_drank = 0;
        }
        void drink_rum()
        {
            rums_drank++;
        }

        void hows_goin_mate()
        {
            if (rums_drank < 5)
                cout << "Nothin!" << endl;
            else
                cout << "Arrrr!" << endl;
        }

    private:
        int rums_drank;
};

int main()
{
    Pirate p;

    p.drink_rum();
    p.hows_goin_mate();
    p.drink_rum();
    p.hows_goin_mate();
    p.drink_rum();
    p.hows_goin_mate();
    p.drink_rum();
    p.hows_goin_mate();
    p.drink_rum();
    p.hows_goin_mate();

    // create a pirate class
    // it should have 2 methods
    // drink_rum()
    // hows_goin_mate()
    // if the drink_rum was called at least 5 times:
    // hows_goin_mate should return "Arrrr!"
    // "Nothin'" otherwise

  return 0;
}
