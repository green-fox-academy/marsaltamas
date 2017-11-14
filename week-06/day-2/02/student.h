#ifndef STUDENT_H
#define STUDENT_H

using namespace std;
#include <string>
#include <iostream>

class Student {
    public:
        string name;
        unsigned int age;
        Student(string name, unsigned int age);
        ~Student();
};

#endif // STUDENT_H
