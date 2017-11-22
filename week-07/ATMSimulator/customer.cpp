#include "customer.h"


Customer::Customer(string name, int pin_code, int balance)
{
    this->name = name;
    this->pin_code = pin_code;
    this->login_tries = 3;
    this->balance = balance;
    this->prevelage = CUSTOMER;
};
