#ifndef INPUTPROCESSOR_H
#define INPUTPROCESSOR_H

#include <vector>
#include <iostream>
#include <string>
#include "commands.h"

using  namespace std;


class InputProcessor
{
    public:
        InputProcessor();
        void command_add_task(string command_parameters);
        string get_input();
        vector<string> split_input(string input);

    private:
        string input;
        vector<string> split_intup_vector;

};

#endif // INPUTPROCESSOR_H
