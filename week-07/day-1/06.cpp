#include <iostream>
#include <stdexcept>

using namespace std;

// Create a function which throws a bulit-in exception
// In the main(), put that function in a try block
// Also in the main() catch, what your function throws

void is_divider_zero(int divider);

int main()
{
    try {
        int a = 4;
        int b = 2;

        is_divider_zero(b);
        cout << "a / b = " << a / b << endl;

        b = 0;
        is_divider_zero(b);
        cout << "a / b = " << a / b << endl;

    } catch (runtime_error &err) {
        cout << err.what();
    }

	return 0;
}

void is_divider_zero(int divider)
{
   if (!divider)
        throw runtime_error("You can not divide by zero.\n");
}
