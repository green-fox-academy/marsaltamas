#include <iostream>
#include <vector>

using namespace std;

//create an integer vector with the size of 5 and print the 3rd element of it

int main() {

    vector<int> int_vector;

    for (int i = 0; i < 5; ++i) {
        int_vector.push_back(i);
    }

    for (int i = 0; i < int_vector.size(); ++i) {
        cout << int_vector[i] << endl;
    }

    // printing 3rd element
    cout << "3rd element: " << int_vector.at(2);

    return 0;
}
