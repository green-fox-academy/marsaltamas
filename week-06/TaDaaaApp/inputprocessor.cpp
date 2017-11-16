#include "inputprocessor.h"

string InputProcessor::get_input()
{
    getline(cin, input);
    cout << input;

    return input;
}
