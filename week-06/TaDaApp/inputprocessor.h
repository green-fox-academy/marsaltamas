#ifndef INPUTPROCESSOR_H
#define INPUTPROCESSOR_H

#include <vector>
#include <iostream>
#include <string>

using  namespace std;


class InputProcessor
{
    public:
        InputProcessor();
        vector<string> split_input(string input);

    private:
        string get_input();
        string input;
        vector<string> split_intup_vector;
};

#endif // INPUTPROCESSOR_H
