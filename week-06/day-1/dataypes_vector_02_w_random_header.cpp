#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <random>

using namespace std;

int main()
{
    //Create a vector of integers
    //reserve place for 10 element, then fill those place with random numbers between 0 and 10

    vector<int> rand_int_vector(15);

    random_device generator;
    mt19937 engine(generator());
    uniform_int_distribution<int> distribution(0, 10);

    for (int i = 0; i < rand_int_vector.size(); i++) {
        rand_int_vector.at(i) = distribution(engine);
    }

    for (int i = 0; i < rand_int_vector.size(); i++) {
        cout << "rand_int_vector[" << i << "]: " << rand_int_vector[i] << endl;
    }

    return 0;
}
