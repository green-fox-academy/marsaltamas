#ifndef COMMANDS_H
#define COMMANDS_H

#include <vector>
#include <string>
#include <iostream>
#include "tasks.h"
#include "operationloop.h"
using namespace std;

class Commands
{
    private:
        vector<string> commands = {
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
        void select_command(int command_id, string command_parameters);
        int find_command_ID(string command);
        void command_add_task(string command_parameters);
        void command_exit();
};

#endif // COMMANDS_H
