// Create a student Class
// that has a method `add_grade`, that takes a grade from 1 to 5
// an other method `get_average`, that returns the average of the
// grades
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student
{
    private:
        string name;
        vector<int> v_int_grades;
    public:
        Student(string name, vector<int> v_int_grades);
        ~Student();
        void set_name(string name);
        string get_name();
        void add_grade(int grade);
        int get_grade(int position);
        vector<int> get_grades_vector();
        float get_average();
};

#endif // STUDENT_H
