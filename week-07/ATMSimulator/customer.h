#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "user.h"


class Customer : public User
{
    public:
        Customer(string name, int pin_code, int balance);
    private:
        int balance;
};

#endif // CUSTOMER_H
