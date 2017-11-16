#include "tasks.h"

Tasks::Tasks()
{

}

Tasks::Tasks(string description, bool is_checked, string is_checked_display, int priority)
{
    this->description = description;
    this->is_checked = is_checked;
    this->is_checked_display = is_checked_display;
    this->priority = priority;
}

string Tasks::get_description()
{
    return description;
}

bool Tasks::get_is_checked()
{
    return true;
}

int Tasks::get_priority()
{
    return 2;
}

void Tasks::add_task(Tasks task)
{
    //task_vector.push_back(task);
}

void Tasks::print_tasks()
{
    //cout << "size of task_vector: " << task_vector.size() << endl;

   // if (!task_vector.size()) {
        cout << "******************************|TASK LIST IS EMPTY|******************************\n";
   // } else {
            //cout << task_vector.at(0).get_description() << endl;
     //   }
}
