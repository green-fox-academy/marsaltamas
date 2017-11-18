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
        int command_id;
        vector<string> command_vector = {
            "-a",   //0
            "-wr",  //1
            "-rd",  //2
            "-e",   //3
            "-rm",  //4
            "-c",   //5
            "-p",   //6
            "-lp",  //7
            "-x",   //8
            "-cl",   //9
            "-l"    //10
        };
        vector<string> split_input_string;
        vector<Task> *task_vector_pointer;

    public:
        Commands(vector<string> split_input_string, vector<Task> *task_vector_pointer);
        Commands(vector<Task> *task_vector_pointer);
        int get_command_id();
        bool call_command(int command_id);
        void command_add_task(string command_parameters);
        void command_exit();
        void command_print_tasks();
        void command_wtf();
        void command_rff();
};

#endif // COMMANDS_H
