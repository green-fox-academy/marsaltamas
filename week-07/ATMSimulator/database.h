#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include "user.h"
#include "database.h"
#include "user.h"
#include "customer.h"
#include "admin.h"
#include <fstream>

class DataBase
{
    public:
        DataBase();
        int get_amount_of_cash_in_atm();
        void top_up_amount_of_cash_in_atm();
        User* get_user(int i);
        vector<User*> get_user_vector();
        void check_atm_balance();
        void save_to_file(string file_path);
        bool is_user(int i);
    private:
        std::vector<User*> users_vector;
        int amount_of_cash_in_atm;

};

#endif // DATABASE_H
