#include "task.h"

Task::Task(string description)
{
    this->description = description;
}

Task::Task()
{

}

string Task::get_description()
{
    return description;
}

 void Task::set_description(string description)
 {
     this->description = description;
 }
