#include "task.h"

Task::Task()
{

}

Task::Task(string description, bool is_checked, string is_checked_display, int priority)
{
    this->description = description;
    this->is_checked = is_checked;
    this->is_checked_display = is_checked_display;
    this->priority = priority;
}

string Task::get_description()
{
    return description;
}

bool Task::get_is_checked()
{
    return true;
}

int Task::get_priority()
{
    return 2;
}

void Task::add_task(Task task)
{
    //task_vector.push_back(task);
}

void Task::print_Task()
{
    //cout << "size of task_vector: " << task_vector.size() << endl;

   // if (!task_vector.size()) {
        cout << "******************************|TASK LIST IS EMPTY|******************************\n";
   // } else {
            //cout << task_vector.at(0).get_description() << endl;
     //   }
}
