#include "opeartaionloop.h"
#include "inputprocessor.h"

void OpeartaionLoop::operation_prompt()
{
    bool to_keep_looping;
    task_vector_pointer = &task_vector;

    do {
        InputProcessor ip;
        set_split_input_string(ip.split_input(ip.get_input()));
        task_vector.push_back(split_input_string.at(1));
        Commands c(split_input_string, task_vector_pointer);
        to_keep_looping = c.call_command(c.get_command_id());
    } while (to_keep_looping);
        cout << "printing task tesy from ol: " << task_vector.at(0).get_description();
}

 Task OpeartaionLoop::get_task(int pos)
 {
     return task_vector.at(pos);
 }

 void OpeartaionLoop::set_split_input_string(vector<string> split_input_string)
 {
     this->split_input_string = split_input_string;
 }
