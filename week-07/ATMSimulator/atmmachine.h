#ifndef ATMMACHINE_H
#define ATMMACHINE_H

#include "user.h"
#include <vector>
#include "database.h"

#include <iostream>

using namespace std;

class ATMMachine
{
    public:
        void boot();
        void print_menu();
        void login();
    private:
        DataBase db;

};

#endif // ATMMACHINE_H
