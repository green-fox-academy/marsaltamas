#include "inputprocessor.h"

string InputProcessor::get_input()
{
    getline(cin, input, '\n');
    cout << input;

    return input;
}

vector<string> InputProcessor::tokenize_input(string input)
{
    size_t space_positions = 0;
    string space = " ";
    string parenthesis = "\"";

    space_positions = input.find(parenthesis);
    cout << endl << space_positions << endl;
    space_positions = input.find(parenthesis, space_positions + 1);
    cout << space_positions << endl;

    return string_split;
}
