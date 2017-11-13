#include <iostream>
#include <string>
#include <random>
#include <vector>

//create a vector of integers with the size of 20
//fill this vector with random numbers from 0 to 10
//print the items of the vector
//remove the even numbers, then print the items again

using namespace std;

int main()
{
    random_device generator;        // setting generator device
    mt19937 engine(generator());    // seeding rand generator
    uniform_int_distribution<int> distribution(0, 10); // setting range

    vector<int> rand_int_vector(20);

    // filling up vector
    for (int i = 0; i < rand_int_vector.size(); ++i) {
        rand_int_vector.at(i) = distribution(engine);
    }

    // printing vector
    for (int i = 0; i < rand_int_vector.size(); ++i) {
        cout << "rand_int_vector[" << i << "]: " << rand_int_vector.at(i) << endl;
    }

    cout << "-------------\n";

    // remove even numbers, iterating with iterator
    vector<int>::const_iterator i;

    for (i = rand_int_vector.begin(); i != rand_int_vector.end(); ++i) {
        if (!(*i % 2)) {
            rand_int_vector.erase(i);
            i--;
        }
    }

    for (int i = 0; i < rand_int_vector.size(); ++i) {
        cout << "rand_int_vector[" << i << "]: " << rand_int_vector.at(i) << endl;
    }

    cout << "Printing again with different iteration method: " << endl;

    for (int x : rand_int_vector)
        cout << x << endl;

    return 0;
}
