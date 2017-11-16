#include "commands.h"

int Commands::find_command_ID(string command)
{
    command_id = -1;

    for (unsigned int i = 0; i < commands.size(); i++) {

         if (!commands.at(i).compare(command)) {
                cout << "i found a match";
                command_id = i;
                break;
         }
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
                OperationLoop ol;
                ol.operationPrompt();
        }
}

void Commands::command_add_task(string command_parameters)
{

    Tasks t(command_parameters, false, "[ ]", 0);
    Tasks *tp = new Tasks();
    tp = &t;
    OperationLoop ol;
    ol.operationPrompt();

//    size_t occurances_of_double_qm = count(input.begin(), input.end(),  '\"');
//    cout << "doubleqm occurrances: " << occurances_of_double_qm << endl;
//    size_t space_positions[occurances_of_double_qm];
//    space_positions[0] = input.find( double_qm);
//    cout << endl << space_positions << endl;
//    space_positions[1] = input.find(double_qm, space_positions[0] + 1);
//    cout << space_positions[0] << endl;
//    cout << space_positions[1] << endl;
}

void command_exit()
{
    exit(0);
}
