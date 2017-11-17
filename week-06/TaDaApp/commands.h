#ifndef COMMANDS_H
#define COMMANDS_H


#include <vector>
#include <string>
#include <iostream>
#include "opeartaionloop.h"


using namespace std;

class Commands
{
    private:
//        int command_array_size;
//       string command_array[];
//        enum command_enum  {
//            A,
//            WR,
//            RD,
//            E,
//            RM,
//            C,
//            P,
//            LP,
//            X,
//            CL};
        int command_id;
//        string command_array[] = {
//        "-a",   //0
//        "-wr",  //1
//        "-rd",  //2
//        "-e",   //3
//        "-rm",  //4
//        "-c",   //5
//        "-p",   //6
//        "-lp",  //7
//        "-x",   //8
//        "-cl"   //9
//        };
        vector<string> split_input_string;

    public:
        Commands();
        Commands(vector<string> split_input_string);
        void select_command(int command_id, string command_parameters);
        int find_command_id(string command);
        Task command_add_task(string command_parameters);
        void command_exit();
        string get_command_arr_at(int pos);
        vector<string> command_vector;
        void execute_command(int command_id, vector<string> split_up_string_vector);
        int get_command_id();
};

#endif // COMMANDS_H
