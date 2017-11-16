#include "tasks.h"

Tasks::Tasks(string description, bool is_checked, string is_checked_display, int priority)
{
    this->description = description;
    this->is_checked = is_checked;
    this->is_checked_display = is_checked_display;
    this->priority = priority;
}

string Tasks::get_description()
{
    return "valami";
}

bool Tasks::get_is_checked()
{
    return true;
}

int Tasks::get_priority()
{
    return 2;
}

vector<Tasks> Tasks::get_task_vector()
{
    return task_vector;
}

void Tasks::add_task(Tasks task)
{
    task_vector.push_back(task);
}
