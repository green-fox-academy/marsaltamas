#include <iostream>
#include <stdexcept>

using namespace std;

/* Write a function which is called "get_fibonacci_number". It returns the "N"th
 * Fibonacci number, where "N" is received as a paramter.
 * For example:
 *  - get_fibonacci_number(1) returns 0
 *  - get_fibonacci_number(2) returns 1
 *  - get_fibonacci_number(3) returns 1
 *  - get_fibonacci_number(4) returns 2
 *  - get_fibonacci_number(5) returns 3
 *  - get_fibonacci_number(6) returns 5
 *
 *  If the function gets invalid parameter
 *  Negative numbers are invalid parameters.
 *  It should throw an exception
 */

void is_parameter_valid(int parameter);
int get_fibonacci_number(int n_th_fib);

int main()
{
    for (int i = 0; i < 7; ++i) {

        try {
            cout << "Fib @: " << i << " = " << get_fibonacci_number(i) << endl;
        } catch (runtime_error &err) {
            cout << err.what();
        }

    }


	return 0;
}

void is_parameter_valid(int parameter)
{
    if (parameter < 1)
        throw runtime_error("The parameter must be an integer bigger than -1.\n");
}

int get_fibonacci_number(int n_th_fib)
{
    int a = 0;
    int b = 1;
    int temp = 0;

        is_parameter_valid(n_th_fib);

        if (n_th_fib == 1) {
            return 0;
        } else if (n_th_fib == 2){
            return 1;
        } else {
            is_parameter_valid(n_th_fib);
            for (int i = 2; i < n_th_fib; ++i) {
            temp = b;
            b = a + b;
            a = temp;
            }
            return b;
        }
}
