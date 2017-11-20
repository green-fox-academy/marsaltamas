#include <iostream>
#include <stdexcept>

using namespace std;
//Try to run the following code!
//The program should compile but crash!
//Create a solution for this problem using try-catch block!

int main()
{
    int int_array[5] = {1, 2, 3, 4, 5};

    try {
        int position = -1;

        if (position > sizeof(int_array) - 1 || position < 0)
            throw runtime_error ("Requested position is out of array bounds.");

         cout << int_array[position];

    } catch (runtime_error &err) {
        cout << err.what() << endl;
    }

    return 0;
}
