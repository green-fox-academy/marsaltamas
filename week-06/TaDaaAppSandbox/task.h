#ifndef TASK_H
#define TASK_H

#include <string>
using namespace std;

class Task
{
    public:
        Task();
        Task(string description);
        Task(string description, int priority, bool is_checked);
        string get_description();
        void set_description(string description);
        void set_is_checked(bool status);
        void set_priority(int priority);
        string get_checked_display();
        int get_priority();
        void set_checked_display(string checked_display);

    private:
        string description;
        int priority;
        bool is_checked;
        string checked = " [x] ";
        string not_checked = " [ ] ";
        string checked_display;
        bool get_is_checked();
};

#endif // TASK_H
