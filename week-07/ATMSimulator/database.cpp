#include "database.h"

DataBase::DataBase()
{
    users_vector.push_back(Customer("Alan", 1111, 100));
    users_vector.push_back(Customer("Bale", 2222, 200));
    users_vector.push_back(Customer("Celane", 3333, 300));
    users_vector.push_back(Admin("Admin", 11111111));
    amount_of_cash_in_atm = 5000;
};

int DataBase::get_amount_of_cash_in_atm()
{

    return 4;
};

void DataBase::set_amount_of_cash_in_atm()
{

};
