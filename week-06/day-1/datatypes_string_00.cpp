#include <iostream>
#include <string>

using namespace std;

// Write a program that prints a few details to the terminal window about you
// It should print each detail to a new line.
//  - Your name
//  - Your age
//  - Do you like coffee? (as a boolen variable)
//
//  Example output:
//  John Doe
//  31
//  Likes coffee: true

int main()
{
    string name = "Tamas";
    int age = 31;
    bool likeCoffee = true;
    string string_likeCoffee = "";

    if (likeCoffee)
        string_likeCoffee = "true";
    else
        string_likeCoffee = "false";

    cout << name << endl << age << endl << "Likes coffe: " << string_likeCoffee << endl;

    return 0;
}
