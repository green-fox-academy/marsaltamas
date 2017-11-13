#include <iostream>
#include <vector>

using namespace std;

//create an integer vector with the size of 5 and print all elements of it

int main() {

    vector<int> int_vector(5);

    for (int i = 0; i < int_vector.size(); ++i) {
        cout << int_vector.at(i) << endl;
    }

    for (int i = 0; i < int_vector.size(); ++i) {
        int_vector.at(i) = i;
    }

    cout << "----\n";

    for (int i = 0; i < int_vector.size(); ++i) {
        cout << int_vector.at(i) << endl;
    }


    return 0;
}
