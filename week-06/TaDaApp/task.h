#ifndef TASK_H
#define TASK_H

#include <string>
using namespace std;

class Task
{
    public:
        Task(string description);
        string get_description();
    private:
        string description;

};

#endif // TASK_H
