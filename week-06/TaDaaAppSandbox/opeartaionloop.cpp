#include "opeartaionloop.h"
#include "inputprocessor.h"

void OpeartaionLoop::operation_prompt()
{
    bool keep_looping;

    // dummy tasks for testing
    task_vector_pointer = &task_vector;
    task_vector.push_back(Task("task1", 1, false));
    task_vector.push_back(Task("task2", 1, false));
    task_vector.push_back(Task("task3", 1, false));
    task_vector.push_back(Task("task4", 1, false));
    task_vector.push_back(Task("task5", 1, false));
    task_vector.push_back(Task("task6", 1, false));
    task_vector.push_back(Task("task7", 1, false));
    task_vector.push_back(Task("task8", 1, false));
    task_vector.push_back(Task("task9", 1, false));
    task_vector.push_back(Task("task10", 1, false));

    //task_vector.add(Task())

    do {
        InputProcessor ip;
        set_split_input_string(ip.split_input(ip.get_input()));
        Commands c(split_input_string, task_vector_pointer);
        keep_looping = c.call_command(c.get_command_id());
    } while (keep_looping);
}

 Task OpeartaionLoop::get_task(int pos)
 {
     return task_vector.at(pos);
 }

 void OpeartaionLoop::set_split_input_string(vector<string> split_input_string)
 {
     this->split_input_string = split_input_string;
 }

