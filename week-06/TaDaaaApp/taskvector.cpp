#include "taskvector.h"

//TaskVector::Taskvector()
//{
//
//}
//
//TaskVector::Taskvector(string description, bool is_checked, string is_checked_display, int priority)
//{
//    this->description = description;
//    this->is_checked = is_checked;
//    this->is_checked_display = is_checked_display;
//    this->priority = priority;
//}
//
void TaskVector::add_task_to_vector(Tasks task)
{
    task_vector.push_back(task);
}
