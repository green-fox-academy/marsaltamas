#include <iostream>
#include <stdexcept>

using namespace std;

/**
 * Create a function that prints out the fist "N" positive odd numbers.
 * It should take the "N" number as a parameter, and print the output to the console.
 *
 * The output should look like this for 5 as parameter:
 *   1, 3, 5, 7, 9
 *
 * Non-positive "N" numbers should be treated as errors, handle it!
 */

void is_parameter_valid(int parameter);
void print_odd_numbers(int how_many);


int main()
{
    print_odd_numbers(0);

    return 0;
}

void is_parameter_valid(int parameter)
{
    if (parameter < 1)
        throw runtime_error("Your should provide an integer above zero.\n");
}

void print_odd_numbers(int how_many)
{
    int counter = 0;

    try {

    is_parameter_valid(how_many);

    for (int i = 1;;++i) {
        if (i % 2) {
            cout << i << " ";
            counter++;
                if (counter == how_many)
                    break;
        }
    }

    } catch (runtime_error &err) {
        cout << err.what();
    }


}
