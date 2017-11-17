#ifndef TASK_H
#define TASK_H

#include <string>
using namespace std;

class Task
{
    public:
        Task();
        Task(string description);
        string get_description();
        void set_description(string description);
    private:
        string description;

};

#endif // TASK_H
