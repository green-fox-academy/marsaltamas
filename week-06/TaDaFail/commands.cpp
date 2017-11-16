#include "commands.h"

Commands::Commands()
{
    string command_array[] = {
        "-a",   //0
        "-wr",  //1
        "-rd",  //2
        "-e",   //3
        "-rm",  //4
        "-c",   //5
        "-p",   //6
        "-lp",  //7
        "-x",   //8
        "-cl"   //9
    };

    for (int i = 0; i < 10; i++) {
        command_vector.push_back(command_array[i]);
    }

}

int Commands::find_command_ID(string command)
{
    command_id = -1;

    for (unsigned int i = 0; i < command_vector.size(); i++) {

         if (!command_vector.at(i).compare(command)) {
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

    Task t(command_parameters, false, "[ ]", 0);
    Task *tp = new Task();
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
