#ifndef SCREENTEMPLATE_H
#define SCREENTEMPLATE_H

#include <iostream>
#include <string>
#include <iostream>

using namespace std;

class ScreenTemplate
{
    private:
        string header =
            "                            *************************\n"
            "                            ******TaDaaaaaa App******\n"
            "                            *************************\n"
            "--------------------------------------------------------------------------------\n"
            "nr.|done?|pri|                  task description\n"
            "--------------------------------------------------------------------------------\n";
        string foot =
            "--------------------------------------------------------------------------------\n"
            "-a Add new task|-wr Save|-rd Load| -e Empty list| -rm Remove task| -c Check task\n"
            "--------------------------------------------------------------------------------\n"
            "***********|-p Add task with priority|-lp  Lists by priority|-x Exit************\n"
            "--------------------------------------------------------------------------------\n"
            "*****************************|ENTER COMMANDS BELOW|*****************************\n";
    public:
        void print_header();
        void print_foot();
};

#endif // SCREENTEMPLATE_H
