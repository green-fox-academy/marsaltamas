#include <iostream>
#include <string>

using namespace std;

class Student {
    public:
        string name;
        unsigned int age;
        Student(string name, int age)
        {
            this->name = name;
            this->age = age;
        }
        ~Student()
        {
            cout << "Student says by.";
        }
};

int main()
{
  // Create a new instace of the Student class and set it's name to "John" and
  // it's age to 21
    Student john("John", 21);
    cout << john.name << endl;
    cout << john.age << endl;

    return 0;
}
