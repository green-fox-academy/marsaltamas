// Create a student Class
// that has a method `add_grade`, that takes a grade from 1 to 5
// an other method `get_average`, that returns the average of the
// grades
#include "student.h"

int main()
{
    vector<int> grades = {1, 2, 3, 4, 5};

    Student student("Jerry", grades);
    student.get_grades_vector();
    student.add_grade(5);
    student.add_grade(9);
    student.get_grades_vector();

    cout << "Average of the grades: " << student.get_average() << "." << endl;

    return 0;
}
