#include "commands.h"
#include "task.h"


Commands::Commands(vector<string> split_input_string)
{
    this->split_input_string = split_input_string;
    this->command_id = 2;
}

Commands::Commands()
{
//    command_vector.reserve(10);
//
//    command_array_size = sizeof(command_array) / sizeof(command_array[0]);
//
//    for (int i; i < command_vector.size(); i++) {
//        command_vector.push_back(command_array[i]);
//    }
//    cout << command_vector.size() << endl;
}

Commands::Commands(vector<Task> *task_vector_pointer)
{
    this->task_vector_pointer = task_vector_pointer;
    this->command_id = 2;
}

Commands::Commands(vector<string> split_input_string, vector<Task> *task_vector_pointer)
{
    this->split_input_string = split_input_string;
    this->task_vector_pointer = task_vector_pointer;
    this->command_id = 8;
}

void Commands::select_command(int command_id, string command_parameters)
{
//        switch (command_id) {
//            case (A):
//                command_add_task(command_parameters);
//                break;
//            case (WR):
//                break;
//            case (RD):
//                break;
//            case (E):
//                break;
//            case (RM):
//                break;
//            case (C):
//                break;
//            case (P):
//                break;
//            case (LP):
//                break;
//            case (X):
//                break;
//            case (CL):
//                break;
//            default:
//                cout << "Invalid command.\n";
//        }
}



string Commands::get_command_arr_at(int pos)
{
    return "valami"; //command_array[pos];
}




void Commands::command_add_task(string command_parameters)
{
    cout << "command_add_task was called " << endl;
    Task *task_pointer = new Task;
    task_pointer->set_description(command_parameters);
    task_vector_pointer->push_back(*task_pointer);

    //task_vector.push_back(*task);
   // cout << "task desc in commands: " << cout << task->get_description() << endl;


//    size_t occurances_of_double_qm = count(input.begin(), input.end(),  '\"');
//    cout << "doubleqm occurrances: " << occurances_of_double_qm << endl;
//    size_t space_positions[occurances_of_double_qm];
//    space_positions[0] = input.find( double_qm);
//    cout << endl << space_positions << endl;
//    space_positions[1] = input.find(double_qm, space_positions[0] + 1);
//    cout << space_positions[0] << endl;
//    cout << space_positions[1] << endl;
}

int Commands::get_command_id()
{
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
            cout << "Program quits.";
            return false;
        default:
            cout << "Invalid command" << endl;
            return true;
     }

    return true;
 }
