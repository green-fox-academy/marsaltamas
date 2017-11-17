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
        string get_checked_display();

    private:
        string description;
        int priority;
        bool is_checked;
        string checked = "[x]";
        string not_checked = "[ ]";
        string checked_display;
};

#endif // TASK_H
