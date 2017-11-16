#ifndef INPUTPROCESSOR_H
#define INPUTPROCESSOR_H

#include <iostream>
#include <string>
#include <istream>
#include <vector>

using namespace std;

class InputProcessor {

    private:
        string input;
        vector<string> string_split;
    public:
        string get_input();
        vector<string> tokenize_input(string input);
};

#endif // INPUTPROCESSOR_H
