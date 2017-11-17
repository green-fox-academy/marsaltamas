#include "opeartaionloop.h"
#include "inputprocessor.h"

void OpeartaionLoop::operation_prompt()
{
    bool to_keep_looping;

    do {
        InputProcessor ip;
        set_split_input_string(ip.split_input(ip.get_input()));
        task_vector.push_back(split_input_string.at(1));
        Commands c(split_input_string);
        to_keep_looping = call_command(c.get_command_id(), split_input_string);
    } while (to_keep_looping);
}

 Task OpeartaionLoop::get_task(int pos)
 {
     return task_vector.at(pos);
 }

 void OpeartaionLoop::set_split_input_string(vector<string> split_input_string)
 {
     this->split_input_string = split_input_string;
 }

bool OpeartaionLoop::call_command(int command_id, vector<string> split_input_string)
 {
     Commands c;
     switch (command_id) {
         case 0: //add_task
            task_vector.push_back(c.command_add_task(split_input_string.at(1)));
            break;
        default:
            return false;
     }

        return true;
 }
