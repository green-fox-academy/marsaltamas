#include "pirate.h"

Pirate::Pirate()
{
    rum_drank = 0;
    cout << "Pirate been created, and has drank " << rum_drank << " rums so far." << endl;
}

Pirate::~Pirate()
{
    cout << "Pirate finished drinking for today.";
}

void Pirate::drink_rum()
{
    rum_drank++;
    cout << "Pirate has drank " << rum_drank << " rums so far." << endl;
}

string Pirate::hows_goin_mate()
{
    if (rum_drank >5)
        return "-How's goin mate?\n-Arrrrr!\n";
    else
        return "-How's goin mate?\n-Nothing...\n";
}
