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

string Task::get_description()
{
    return description;
}

 void Task::set_description(string description)
 {
     this->description = description;
 }

 string Task::get_checked_display()
 {
     return checked_display;
 }
