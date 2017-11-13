#include <iostream>
#include <string>

using namespace std;

/**
 * Please create a program that asks for a count when it starts.
 * It should ask for a number count times, then it shoud print the average of the nubmers.
 * It should delete any dynamically allocated resource before the program exits.
 */

int main()
{
    int cnt = 0;
    int *p = NULL;

    cout << "Please enter how many numbers you will enter: " << endl;
    cin >> cnt;

    p = new int[cnt];

    for (int i = 0; i < cnt; ++i) {
        cout << "Please enter number nr." << i + 1 << ": " << endl;
        cin >> *(p + i);
    }

    for (int i = 0; i < cnt; ++i) {
        cout << "p[" << i + 1 << "]: " << *(p + i) << endl;
    }

    delete []p;

    return 0;
}
