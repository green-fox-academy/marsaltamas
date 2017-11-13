#include <iostream>
#include <string>

using namespace std;

#include "mark.h"
#include "maria.h"

int sum_of_age (int age_1, int age_2);

// Create your own namespace, called Mark
// store your name as a string
// your age as an integer
// and your favorite number as an integer
//
// Create your own namespace, called Maria
// store your name as a string
// your age as an integer
// and your favorite number as an integer
//
// create a function that can add the two age, and returns it

int main()
{
    cout << "Sum of the two ages: " << sum_of_age(mark :: age, maria :: age);

    return 0;
}

int sum_of_age (int age_1, int age_2)
{
    return age_1 + age_2;
}
