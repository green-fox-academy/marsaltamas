#include <iostream>
using namespace std;

// Write a try - catch block.
// Throw an integer in the try block
// Catch it in the catch block and write it out.

int main()
{
    try {
        int a = 5;
        int b = 0;

        if (!b) {
            throw b;
        }

    } catch (int n) {
        cout << n;
    }

	return 0;
}
