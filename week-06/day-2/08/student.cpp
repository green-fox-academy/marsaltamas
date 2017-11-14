#include "student.h"

Student::Student(string name, vector<int> v_int_grades)
{
    this->name = name;
    this->v_int_grades;
}

Student::~Student()
{
        cout << "Student finished studies.";
}

void Student::set_name(string name)
{

}

string Student::get_name()
{
    return name;
}

void Student::add_grade(int grade)
{

}

int Student::get_grade(int position)
{
    return 2;
}

vector<int> Student::get_grades_vector()
{
    vector<int> grades;

    return grades;
}

float Student::get_average()
{
    return 2;
}
