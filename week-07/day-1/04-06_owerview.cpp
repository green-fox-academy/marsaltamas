#include <iostream>
#include <stdexcept>

using namespace std;

void is_divider_zero(int a, int b) throw (int, char, runtime_error);

int main()
{
    try {

        int a = 4;
        int b = 4;

        is_divider_zero(a, b);

    } catch (...) {
        cout << "there was an error.";
    }

	return 0;
}

void is_divider_zero(int a, int b) throw (int, char, runtime_error)
{
    if (!b) {
            throw 0;
        } else if (a == b) {
            throw 'e';
        } else if (b == 1) {
            throw runtime_error("Error");
        }
}
