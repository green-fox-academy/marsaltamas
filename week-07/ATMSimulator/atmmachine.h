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
        void print_admin_menu();
        int login();
        void run();
        void operation_prompt(int mode);
        void quit_routine();
        void customer_mode();
        void admin_mode();
        void withdraw();
        void check_balance();
        void who_is_the_richest();

    private:
        DataBase *db;
        User *active_user;

};

#endif // ATMMACHINE_H
