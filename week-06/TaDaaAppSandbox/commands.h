#ifndef COMMANDS_H
#define COMMANDS_H


#include <vector>
#include <string>
#include <iostream>
#include "opeartaionloop.h"
#include "task.h"


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
        vector<Task> *task_vector_pointer;

    public:
        Commands();
        Commands(vector<string> split_input_string);
        Commands(vector<string> split_input_string, vector<Task> *task_vector_pointer);
        Commands(vector<Task> *task_vector_pointer);
        void select_command(int command_id, string command_parameters);
        void command_add_task(string command_parameters);
        void command_exit();
        string get_command_arr_at(int pos);
        vector<string> command_vector;
        int get_command_id();
        bool call_command(int command_id);
};

#endif // COMMANDS_H
