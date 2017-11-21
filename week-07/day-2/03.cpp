#include <iostream>
using namespace std;

// Now, create 2 functions. They should bear the same name.
// These functions should multiple their parameters.
// The first should return float and take two arguments of the type float.
// The second function should return int and take two arguments of integer type.
// Use these two functions and print out the results.

int multiplication(int a, int b)
{
    return a * b;
}

float multiplication(float a, float b)
{
    return a * b;
}
//
// Compile the code You wrote. Note the output of the compiler. Think about it, google it.
// Now, put one of the functions into comment. (So it's still legible but won't compile.)
// Try compiling it again, and watch what the results are.
//
// Switch the two function declarations. Uncomment the one You commented out and comment out the one
// that ran before. Compile it and compare the results again.
//
// What did You learn from this exercise?
// Write it down in a comment into Your file!

int main()
{
    int a = 2;
    int b = 3;

    float a_f = 2.0f;
    float b_f = 3.2f;

    cout << "int multiplicator: " << multiplication(a, b) << endl;
    cout << "float multiplicator: " << multiplication(a_f, b_f) << endl;

    return 0;
}
