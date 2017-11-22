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
        ~ATMMachine();
        void boot();
        void print_customer_menu();
        int login();
        void run();
        void operation_prompt(int mode);
        void quit_routine();

    private:
        DataBase *db;
        User *active_user;

};

#endif // ATMMACHINE_H
