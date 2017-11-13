#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Define several things as a variable then print their values
// Your name as a string
// Your age as an integer
// Your height in meters as a double
// Whether you are married or not as a boolean

int main()
{
    string name = "Tamas";
    int age = 31;
    double height = 1.78;
    bool married = false;

    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Height: " << height << endl;
    cout << "Married?: ";
    cout << boolalpha;
    cout << married << endl;

    return 0;
}
