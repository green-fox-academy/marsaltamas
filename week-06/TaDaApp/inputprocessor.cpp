#include "inputprocessor.h"

InputProcessor::InputProcessor()
{
    this->input = get_input();
    split_input(input);
}

string InputProcessor::get_input()
{
    cout << "Please enter instructions: " << endl;
    getline(cin, input, '\n');

    return input;
}

// command is stored in split_up_vector(1), command parameter will be stored at (2)
vector<string> InputProcessor::split_input(string input)
{
    cout << "split_input called" << endl;
    cout << "input was: " << input << endl;

    split_intup_vector.push_back(input);

    return split_intup_vector;
}
