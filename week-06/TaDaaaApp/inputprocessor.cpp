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

    size_t position_of_space;

    position_of_space = input.find(space);

    if ((int) input.find(space) == -1) { // no space found
        Commands c;
        c.select_command(c.find_command_ID(input));
    } else {
        string command = input.substr(0, position_of_space);
        string comman_parameter = input.substr(position_of_space + 1, input.size());
        Commands c;
        c.select_command(command, comman_parameter);
    }

//    size_t occurances_of_double_qm = count(input.begin(), input.end(),  '\"');
//    cout << "doubleqm occurrances: " << occurances_of_double_qm << endl;
//    size_t space_positions[occurances_of_double_qm];
//    space_positions[0] = input.find( double_qm);
//    cout << endl << space_positions << endl;
//    space_positions[1] = input.find(double_qm, space_positions[0] + 1);
//    cout << space_positions[0] << endl;
//    cout << space_positions[1] << endl;

}
