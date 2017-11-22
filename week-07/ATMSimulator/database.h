#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include "user.h"

class DataBase
{
    public:
        /** Default constructor */
        DataBase();
    private:
        std::vector<User> users;
        int amount_of_cash_in_atm;
};

#endif // DATABASE_H
