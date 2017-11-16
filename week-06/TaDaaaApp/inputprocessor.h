#ifndef INPUTPROCESSOR_H
#define INPUTPROCESSOR_H

#include <iostream>
#include <string>
#include <istream>
#include <vector>
#include "commands.h"


using namespace std;

class InputProcessor {

    private:
        string input;
    public:
        string get_input();
        void command_selector(string input);

};

#endif // INPUTPROCESSOR_H
