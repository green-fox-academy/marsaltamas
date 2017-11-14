#include "house.h"

int main()
{
  // The market price of the houses is 400 EUR / square meters
  // Make the get_price() function work
  // Create a constructor for the House class that takes it's address and area.
    House house = House("Andrassy 66", 349);
    cout << house.get_price(house.get_area()) << endl;

    return 0;
}
