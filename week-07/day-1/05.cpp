#include <iostream>
using namespace std;

// Create a function which throws a char
// In the main(), put that function in a try block
// Also in the main() catch, what your function throws

void is_divider_zero(int dividerr);

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

    } catch (char error) {
        cout << error;
    }

	return 0;
}

void is_divider_zero(int dividerr)
{
    if (!dividerr)
        throw 'e';
}
