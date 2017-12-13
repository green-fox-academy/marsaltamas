#include <iostream>
#include <string>

using namespace std;

class Car {
    public:
        Car(string _type, int _km)
        {
            type_ = _type;
            km_ = _km;
        }

        void run(int _kms_to_add)
        {
            km_+= _kms_to_add;
        }

        int get_km()
        {
            return km_;
        }
    private:
        string type_;
        int km_;
};

int main()
{
    // Create a class called "Car"
    // It should have a "type" property that stores the car's type in a string eg: "Mazda"
    // It should have a "km" property that stores how many kilometers it have run
    // The km and the type property should be a parmeter in the constructor
    // It should have a method called "run" that takes a number and increments the "km" property by it

    Car c("lada", 10);
    c.run(50);
    cout << c.get_km() << endl;

    return 0;
}
