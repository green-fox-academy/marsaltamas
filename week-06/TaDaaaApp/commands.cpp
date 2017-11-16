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
}

void Commands::select_command(int command_id)
{
        switch (command_id) {
            case (A):
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
                "Invalid command.\n";
        }
}

void Commands::select_command(string command, string command_parameters)
{
    cout << "command with paramtere was called" << endl;
}


