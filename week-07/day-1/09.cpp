#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

/**
 * Create a function that prints a multiplication table with a given base number.
 * It should take the base number as a parameter, and print the output to the console.
 *
 * The output should look like this for 5 as base:
 *   1 * 5 = 5
 *   2 * 5 = 10
 *   3 * 5 = 15
 *   4 * 5 = 20
 *   5 * 5 = 25
 *   6 * 5 = 30
 *   7 * 5 = 35
 *   8 * 5 = 40
 *   9 * 5 = 45
 *   10 * 5 = 50
 *
 *  If the function gets invalid parameter
 *  Negative numbers are invalid parameters.
 *  It should throw an exceptions
 */

void is_base_valid(int base);
void print_mult_talbe_at_base(int base);

int main()
{
    try {

        print_mult_talbe_at_base(-1);

    } catch (runtime_error &err) {
        cout << err.what() << endl;
    }

    return 0;
}

void is_base_valid(int base)
{
    if (base < 0)
        throw runtime_error("Base must be zero or greater.");
}

void print_mult_talbe_at_base(int base)
{
    is_base_valid(base);

    for (int i = 1; i < 11; ++i) {
        cout << setw(2) << i << " * " << base << " = " << setw(3) << i * base << endl;
    }
}
