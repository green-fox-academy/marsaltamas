#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include "user.h"
#include "database.h"
#include "user.h"
#include "customer.h"
#include "admin.h"

class DataBase
{
    public:
        DataBase();
        int get_amount_of_cash_in_atm();
        void set_amount_of_cash_in_atm();
    private:
        std::vector<User> users_vector;
        int amount_of_cash_in_atm;

};

#endif // DATABASE_H
