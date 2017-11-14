#include <iostream>
#include <string>

using namespace std;

class Student {
    public:
    string name;
    unsigned int age;
    Student(string name, unsigned int age)
    {
      this->age = age;
      this->name = name;
    }
    string greet()
    {
        return name;
    }

};

int main()
{
    // Create a method on the Student class called "greet" that returns a string
    // like: "Hello my name is: <student name>"

    Student student("John", 21);
    cout << "Hello, my name is " << student.greet() << ".";

    return 0;
}
