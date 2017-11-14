#include <iostream>

using namespace std;

#include "student.h"

int main() {
  // Create a new instace of the Student class and set it's name to "John" and
  // it's age to 21 with it's constructor

  Student john("John", 21);

  cout << john.name << endl;
  cout << john.age << endl;

  return 0;
}
