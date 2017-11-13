#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    //Create a vector of integers
    //reserve place for 10 element, then fill those place with random numbers between 0 and 10

    srand(time(0));

    vector<int> rand_int_vector;
    rand_int_vector.reserve(10);

    for (int i = 0; i < rand_int_vector.capacity(); i++) {
        rand_int_vector.push_back(rand() % 11);
    }

    for (int i = 0; i < rand_int_vector.size(); i++) {
        cout << "rand_int_vector[" << i << "]: " << rand_int_vector[i] << endl;
    }

    return 0;
}
