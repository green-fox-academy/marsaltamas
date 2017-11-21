#include <iostream>
using namespace std;

// create a function that adds two integers.
// Create an other function of the same name that takes 3 integers and returns the result of adding these 3 integers.
// Write code that uses both after one an other and prints out the results in a new line each.
// For input use 1 and 2, then 1, 2 and 3.

int add_ints(int a, int b, int c)
{
    return a + b + c;
}

int add_ints(int a, int b)
{
    return a + b;
}

int main()
{
    int a = 1;
    int b = 2;
    int c = 3;

    cout << "With two ints: " << add_ints(a, b) << endl;
    cout << "With three ints: " << add_ints(a, b, c) << endl;

    return 0;
}
