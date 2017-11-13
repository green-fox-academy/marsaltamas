#include <iostream>
#include <string>

using namespace std;

/**
 * Please create a program that asks for a count when it starts.
 * It should ask for a number count times, then it should print the average of the numbers.
 * It should delete any dynamically allocated resource before the program exits.
 */

int main()
{
    int cnt = 0;
    int *p = NULL;
    int sum = 0;

    cout << "Please enter how many numbers you will enter: " << endl;
    cin >> cnt;

    p = new int[cnt];

    for (int i = 0; i < cnt; ++i) {
        cout << "Please enter number nr." << i + 1 << ": " << endl;
        cin >> *(p + i);
        sum+= p[i];
    }

    for (int i = 0; i < cnt; ++i) {
        cout << "p[" << i + 1 << "]: " << *(p + i) << endl;
    }

    cout << "Sum is: " << sum << endl;
    cout << "Numbers entere: " << cnt << endl;
    cout << "Average is: " << (float) sum / cnt;

    delete []p;

    return 0;
}
