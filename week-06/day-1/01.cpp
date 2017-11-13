#include <iostream>
#include <string>

using namespace std;

// Greet 3 of your classmates with this program, in three separate lines
// like:
//
// Hello, Esther!
// Hello, Mary!
// Hello, Joe!
// Store their names in separate string type variables

int main()
{
    string nameEsther = "Esther";
    string nameMarry = "Marry";
    string nameJoe = "Joe";
    string nameArray[] = {nameEsther, nameMarry, nameJoe};

    for (int i = 0; i < 3; ++i) {
        cout << "Hello " << nameArray[i] << "!" << endl;
    }

    return 0;
}
