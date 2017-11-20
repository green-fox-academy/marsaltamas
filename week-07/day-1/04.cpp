#include <iostream>

using namespace std;

// Create a function which throws an integer
// In the main(), put that function in a try block
// Also in the main() catch, what your function throws

void is_divider_zero(int divider);

int main()
{
    try {
        int a = 4;
        int b = 0;
        is_divider_zero(b);

        cout << "a / b = " << a / b;

    } catch (int error) {
        cout << error;
    }


	return 0;
}

void is_divider_zero(int divider)
{
    if (!divider)
        throw 666;
}
