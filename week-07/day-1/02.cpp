#include <iostream>
using namespace std;

// Write a try - catch block.
// Throw an char in the try block
// Catch it in the catch block and write it out.

int main()
{
    try {

        char test = 'a';

        if (test != 'b')
            throw 'e';

    } catch (char thrown) {
        cout << thrown;
    }

	return 0;
}
