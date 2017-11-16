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

    private:
        string input;
        vector<string> split_intup_vector;
        string get_input();
        vector<string> split_input(string input);
        void call_command(vector<string> split_intup_vector);

};

#endif // INPUTPROCESSOR_H
