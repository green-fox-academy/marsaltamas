#ifndef TASKS_H
#define TASKS_H

#include <string>
#include <vector>
using namespace std;

class Tasks
{
    private:
        vector<Tasks> task_vector;
        string description;
        bool is_checked;
        string is_checked_display;
        int priority;
    public:
        Tasks(string description, bool is_checked, string is_checked_display, int priority);
        string get_description();
        bool get_is_checked();
        int get_priority();
        vector<Tasks> get_task_vector();
        void add_task(Tasks task);
};

#endif // TASKS_H
