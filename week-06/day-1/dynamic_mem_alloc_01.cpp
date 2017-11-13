#include <iostream>

using namespace std;

// Please allocate a 5 long array and fill it with numbers from 0 to 4, then print the whole array
// Please delete the array before the program exits

int main()
{

    int *pointer = NULL;
    int size = 5;

    pointer = new int[size];

    for (int i = 0; i < size; i++) {
        *(pointer + i) = i;
        cout << *(pointer + i) << endl;
    }

    delete []pointer;

    return 0;
}
