#include <iostream>
#include <string>
#define CURRENT_YEAR 2017

using namespace std;

#include "person.h"

// Use your costume namespace from the last exercise
// Create a function, which takes the age as a parameter
// and returns the year when you were born

/*
 * takes int as param
 * returns int == Current year - age of the person
 */
int year_of_birth(int age);

int main()
{
    cout << "The year person was born in: " << year_of_birth(person :: age);

    return 0;
}

int year_of_birth (int age)
{
    return CURRENT_YEAR - age;
}
