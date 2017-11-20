#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

// Create a class named Person.
// This class shoud have a constructor which prints out the
// date of the creation of the istance.

class Person {

    public:
        Person();
};

Person::Person()
{
    time_t tm = time(0);
    string time_string = ctime(&tm);
    cout << "Person been created at " << time_string;
}

int main()
{
    Person p;

    return 0;
}
