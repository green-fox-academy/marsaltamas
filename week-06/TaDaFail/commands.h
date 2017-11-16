#ifndef COMMANDS_H
#define COMMANDS_H

#include <vector>
#include <string>
#include <iostream>
#include "task.h"
#include "operationloop.h"
using namespace std;

class Commands
{
    private:

        vector<string> command_vector;
        string command_array[];
        enum command_enum  {
            A,
            WR,
            RD,
            E,
            RM,
            C,
            P,
            LP,
            X,
            CL};
        int command_id;

    public:
        Commands();
        void select_command(int command_id, string command_parameters);
        int find_command_ID(string command);
        void command_add_task(string command_parameters);
        void command_exit();
};

#endif // COMMANDS_H
