#ifndef COMMANDS_H
#define COMMANDS_H



using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include "task.h"

class Commands
{
    private:
        int command_array_size;
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

    public:
        Commands();
        void select_command(int command_id, string command_parameters);
        int find_command_id(string command);
        void command_add_task(string command_parameters);
        void command_exit();
        string get_command_arr_at(int pos);
        vector<string> command_vector;
};

#endif // COMMANDS_H
