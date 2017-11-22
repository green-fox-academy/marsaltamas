#ifndef ATMMACHINE_H
#define ATMMACHINE_H

#include "user.h"
#include <vector>
#include "database.h"
#include "define.h"

#include <iostream>

using namespace std;

class ATMMachine
{
    public:
        ATMMachine();
        void boot();
        void print_menu();
        int login();
        bool operation_prompt(int mode);
        void quit_routine();
    private:
        DataBase db;
        User ative_user;

};

#endif // ATMMACHINE_H
