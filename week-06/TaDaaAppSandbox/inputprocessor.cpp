#include "inputprocessor.h"

InputProcessor::InputProcessor()
{
    //this->input = get_input();
    //call_command(split_input(input));
}

string InputProcessor::get_input()
{
    cout << "Get input called: Please enter instructions: " << endl;
    getline(cin, input, '\n');

    return input;
}

// command is stored in split_up_vector(1), command parameter will be stored at (2)
vector<string> InputProcessor::split_input(string input)
{
    cout << "split_input called" << endl;
    cout << "input was: " << input << endl;

    string space = " ";
    string command;
    string command_parameters;
    size_t position_of_space = input.find(space);;

    if ((int) position_of_space == -1) { // no space found
        split_intup_vector.push_back(input);
        cout << "command if no space: " << split_intup_vector.at(0) << endl;
        split_intup_vector.push_back("");
        cout << "command parameters if no space: " << split_intup_vector.at(1) << endl;
    } else {
        command = input.substr(0, position_of_space);
        split_intup_vector.push_back(command);
        cout << "command if space found: " << split_intup_vector.at(0) << endl;
        command_parameters = input.substr(position_of_space + 1);
        split_intup_vector.push_back(command_parameters);
        cout << "command parameters space found: " << split_intup_vector.at(1) << endl;
    }

    return split_intup_vector;
}

