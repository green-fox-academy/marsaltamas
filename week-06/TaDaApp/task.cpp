#include "task.h"

Task::Task(string description)
{
    this->description = description;
}

string Task::get_description()
{
    return description;
}
