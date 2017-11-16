#include "inputprocessor.h"
#include <algorithm>

string InputProcessor::get_input()
{
    getline(cin, input, '\n');
    cout << input;

    return input;
}

void InputProcessor::command_selector(string input)
{
    string space = " ";
    string double_qm = "\"";
    string command;
    string command_parameter;

    size_t position_of_space;

    position_of_space = input.find(space);

    if ((int) input.find(space) == -1) { // no space found
        Commands c;
        command_parameter = "";
        c.select_command(c.find_command_ID(input), command_parameter);
    } else {
        command = input.substr(0, position_of_space);
        command_parameter = input.substr(position_of_space + 1, input.size());
        Commands c;
        c.select_command(c.find_command_ID(command), command_parameter);
    }
}
