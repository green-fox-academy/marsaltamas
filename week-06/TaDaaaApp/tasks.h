#ifndef TASKS_H
#define TASKS_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;



class Tasks
{
    private:
        string description;
        bool is_checked;
        string is_checked_display;
        int priority;
    public:
        Tasks();
        Tasks(string description, bool is_checked, string is_checked_display, int priority);
        string get_description();
        bool get_is_checked();
        int get_priority();
        void add_task(Tasks task);
        void print_tasks();
};

#endif // TASKS_H
