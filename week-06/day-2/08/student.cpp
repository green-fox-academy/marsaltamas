#include "student.h"

Student::Student(string name, vector<int> v_int_grades)
{
    this->name = name;
    this->v_int_grades = v_int_grades;
}

Student::~Student()
{
    cout << "Student finished studies.";
}

void Student::set_name(string name)
{
    this->name = name;
}

string Student::get_name()
{
    return name;
}

void Student::add_grade(int grade)
{
    if (grade > 0 && grade < 6)
        v_int_grades.push_back(grade);
    else {
        cout << "You tried to add " << grade << "." << endl;
        cout << "Please add a grade between 1 and 5." << endl;
    }
}

vector<int> Student::get_grades_vector()
{
    cout << "Printing grades of student: " << endl;

    for (int i = 0; i < v_int_grades.size(); i++)
    {
        cout << "grade[" << i << "]: " << v_int_grades.at(i) << endl;
    }
    return v_int_grades;
}

float Student::get_average()
{
    float sum = 0;

    for (int i = 0; i < v_int_grades.size(); i++)
    {
        sum+= v_int_grades.at(i);
    }

    if (!v_int_grades.size())
        cout << "there were no grades found." << endl;
        return 0;
    else
        return sum / v_int_grades.size();
}
