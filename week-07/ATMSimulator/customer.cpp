#include "customer.h"
#include <iostream>

Customer::Customer(string name, int pin_code, int balance)
{
    this->name = name;
    this->pin_code = pin_code;
    this->login_tries = 3;
    this->balance = balance;
    this->prevelage = CUSTOMER;
};

void Customer::set_balance(int change)
{
    balance+= change;
}

int Customer::get_balance()
{
    return balance;
}
