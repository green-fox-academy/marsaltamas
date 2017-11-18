#include "task.h"

Task::Task(string description)
{
    this->description = description;
}

Task::Task()
{
    this->is_checked = false;
    this->checked_display = not_checked;
}

Task::Task(string description, int priority, bool is_checked)
{
    this->description = description;
    this->priority = priority;
    this->is_checked = is_checked;
    this->checked_display = not_checked;
}

string Task::get_description()
{
    return description;
}

 void Task::set_description(string description)
 {
     this->description = description;
 }


bool Task::get_is_checked()
{
    return is_checked;
}

 string Task::get_checked_display()
 {
     if (get_is_checked())
        return checked;
     else
        return not_checked;
 }

void Task::set_is_checked(bool status)
{
    is_checked = status;
}

void Task::set_priority(int priority)
{
    this->priority = priority;
}

int Task::get_priority()
{
    return priority;
}
