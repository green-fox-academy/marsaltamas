#include <iostream>
#include <string>

using namespace std;

#include "joe.h"
#include "elen.h"

int main()
{
    cout << "name 1 " << joe::name << " age of joe: " << joe::age << endl;
    cout << "name 2 " << elen::name << " age of elen: " << elen::age << endl;
    return 0;
}
