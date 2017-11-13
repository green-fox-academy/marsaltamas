#include <iostream>
#include <string>

using namespace std;

// store your personal data in Variables
// string name, int age, int slice_of_pizza_you_can_eat
// allocate memory dynamically for these variables
// create a sentence using these variables
// free the allocated memory

int main() {

    string *p_name = NULL;
    int *p_age = NULL;
    int *p_slices_of_pizza = NULL;

    p_name = new string;
    p_age = new int;
    p_slices_of_pizza = new int;

    *p_name = "Tamas";
    *p_age = 31;
    *p_slices_of_pizza = 10;

    cout << *p_name + " is " << *p_age << " years old and can eat " << *p_slices_of_pizza << " slices of pizza.";

    delete p_name, p_age, p_slices_of_pizza;

    return 0;
}
