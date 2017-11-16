#ifndef TASK_H
#define TASK_H


#include <string>
#include <vector>
#include <iostream>
using namespace std;



class Task
{
    private:
        string description;
        bool is_checked;
        string is_checked_display;
        int priority;
    public:
        Task();
        Task(string description, bool is_checked, string is_checked_display, int priority);
        string get_description();
        bool get_is_checked();
        int get_priority();
        void add_task(Task task);
        void print_Task();
};

#endif // TASK_H
