#include "database.h"

DataBase::DataBase()
{
    users_vector.push_back(User());
    amount_of_cash_in_atm = 5000;
}

int DataBase::get_amount_of_cash_in_atm()
{

    return 4;
};

void DataBase::set_amount_of_cash_in_atm()
{

};
