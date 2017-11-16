#include "commands.h"

Commands::Commands()
{

    command_vector.reserve(10);

    command_array_size = sizeof(command_array) / sizeof(command_array[0]);

    for (int i; i < command_vector.size(); i++) {
        command_vector.push_back(command_array[i]);
    }
    cout << command_vector.size() << endl;
}

int Commands::find_command_id(string command)
{
    cout << "find_command_id was called\n";
    command_id = -1;

    for (int i = 0; i < command_vector.size(); i++) {

        cout << "i entered loop\n" << command_vector.at(i) << endl;
//         if (command) {
//                cout << "i found a match at position: " << i << endl;
//                command_id = i;
//                break;
//       }
    }
    return command_id;
}

void Commands::select_command(int command_id, string command_parameters)
{
        switch (command_id) {
            case (A):
                command_add_task(command_parameters);
                break;
            case (WR):
                break;
            case (RD):
                break;
            case (E):
                break;
            case (RM):
                break;
            case (C):
                break;
            case (P):
                break;
            case (LP):
                break;
            case (X):
                break;
            case (CL):
                break;
            default:
                cout << "Invalid command.\n";
        }
}

void Commands::command_add_task(string command_parameters)
{


//    size_t occurances_of_double_qm = count(input.begin(), input.end(),  '\"');
//    cout << "doubleqm occurrances: " << occurances_of_double_qm << endl;
//    size_t space_positions[occurances_of_double_qm];
//    space_positions[0] = input.find( double_qm);
//    cout << endl << space_positions << endl;
//    space_positions[1] = input.find(double_qm, space_positions[0] + 1);
//    cout << space_positions[0] << endl;
//    cout << space_positions[1] << endl;
}

string Commands::get_command_arr_at(int pos)
{
    return command_array[pos];
}
