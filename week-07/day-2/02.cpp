#include <iostream>
#include <string>

using namespace std;

// Create 3 functions: each should take respectively 2, 3 and 4 strings.
// Each should return a string that contains all the input string concatenated.
// (Combined into one in a linear order.)
// Write code that showcases how this works and prints out the result of the function.

string concat_strings(string one, string two, string three, string four)
{
    return one + two + three + four;
}

string concat_strings(string one, string two, string three)
{
    return one + two + three;
}

string concat_strings(string one, string two)
{
    return one + two;
}

int main()
{
    string one = "one ";
    string two = "two ";
    string three = "three ";
    string four = "four";

    cout << "Calling function adding four strings: " << concat_strings(one, two, three, four) << endl;
    cout << "Calling function adding three strings: " << concat_strings(one, two, three) << endl;
    cout << "Calling function adding two strings: " << concat_strings(one, two) << endl;

	return 0;
}
