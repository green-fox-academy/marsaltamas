#include "commands.h"
#include "task.h"
#include <iomanip>
#include "fileio.h"


Commands::Commands(vector<string> split_input_string, vector<Task> *task_vector_pointer)
{
    this->split_input_string = split_input_string;
    this->task_vector_pointer = task_vector_pointer;
}

void Commands::command_add_task(string command_parameters)
{
    Task *task_pointer = new Task(command_parameters, 0, false);
    task_pointer->set_description(command_parameters);
    task_pointer->set_is_checked(false);
    task_pointer->set_priority(0);
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
            command_wtf();
            break;
         case 2:
            command_rff();
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

    string header =
                    "--------------------------------------------------\n"
                    "              Printing tasks\n"
                    "--------------------------------------------------\n"
                    "nr.|done?|pr.|        Task descripion\n"
                    "--------------------------------------------------\n";

    string footer = "--------------------------------------------------\n";

    cout << header;

    for (unsigned int i = 0; i < task_vector_pointer->size(); ++i) {
        cout << setw(2) << i + 1 << " |" << task_vector_pointer->at(i).get_checked_display() << "| " << task_vector_pointer->at(i).get_priority()
         << " | " << task_vector_pointer->at(i).get_description() << endl;
    }

    cout << footer << endl;
}

void Commands::command_wtf()
{
    FileIO f;
    f.write_to_file(task_vector_pointer);
}

void Commands::command_rff()
{
    FileIO f;
    f.read_from_file(task_vector_pointer);
}
