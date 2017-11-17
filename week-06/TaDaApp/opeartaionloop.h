#ifndef OPEARTAIONLOOP_H
#define OPEARTAIONLOOP_H


#include <vector>
#include <iostream>
#include <string>
#include "task.h"


class OpeartaionLoop
{
    public:
        void operation_prompt();
        Task get_task(int pos);
        void set_split_input_string(vector<string> split_input_string);
        bool call_command(int command_id, vector<string> split_input_string);

    private:
        vector<Task> task_vector;
        vector<string> split_input_string;
        Task task;

};

#endif // OPEARTAIONLOOP_H
