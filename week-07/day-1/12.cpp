#include <iostream>
#include <string>
using namespace std;

// Write a function that can throw two kinds of exceptions: int and const char*
// It should receive an integer.
// It should return a string from the char* array defined below.
// If the integer is larger than 5, throw an integer exception. The value of the exception should be how much larger it is.
// If the integer is less than 0, it should throw a const char* exception stating, that it is a negative number.
//
// Illustrate both cases in the main function.
// HINT: Put each protected code segment in a new try-catch block.

const char* test_throw(int position);

int main()
{
    try {

        test_throw(-1);

    } catch (const char *e) {
        cout << e << endl;
    } catch (int e) {
        cout << "Provided position is greater than the array size by " << e << endl;
    }

    try {

        test_throw(6);

    } catch (const char *e) {
        cout << e << endl;
    } catch (int e) {
        cout << "Provided position is greater than the array size by " << e << endl;
    }

    return 0;
}

const char* test_throw(int position)
{
    const char* sentence[6] = {"What", "a", "pleasant", "surprie", "this", "is."};

    if (position > 5)
        throw position - 5;
    else if (position < 0)
        throw "Requested position must be an integer above -1.\n";

    return sentence[position];
}
