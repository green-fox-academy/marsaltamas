#include "commands.h"
#include "task.h"

Commands::Commands(vector<string> split_input_string, vector<Task> *task_vector_pointer)
{
    this->split_input_string = split_input_string;
    this->task_vector_pointer = task_vector_pointer;
}

void Commands::command_add_task(string command_parameters)
{
    cout << "command_add_task was called " << endl;
    Task *task_pointer = new Task;
    task_pointer->set_description(command_parameters);
    task_vector_pointer->push_back(*task_pointer);
}

int Commands::get_command_id()
{
    command_id = -1;
    for (unsigned int i = 0; i < command_vector.size(); i++) {
        if (!split_input_string.at(0).compare(command_vector.at(i))) {
            command_id = i;
            return command_id;
        }
    }

    return command_id;
}


bool Commands::call_command(int command_id)
 {
     switch (command_id) {
         case 0: //add_task
            command_add_task(split_input_string.at(1));
            break;
         case 1:
            command_add_task(split_input_string.at(0));
            break;
         case 8:
            cout << "Program quits.\n";
            return false;
         case 10:
            command_print_tasks();
            break;
        default:
            cout << "Invalid command" << endl;
     }

    return true;
 }

void Commands::command_print_tasks()
{
    cout << "Printing tasks:" << endl;

    for (unsigned int i = 0; i < task_vector_pointer->size(); ++i) {
        cout << "Task " << i + 1 << ": " << task_vector_pointer->at(i).get_description()
        << task_vector_pointer->at(i).get_checked_display() << endl;
    }
}
