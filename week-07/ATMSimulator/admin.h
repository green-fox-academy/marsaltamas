#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"


class Admin : public User
{
    public:
        Admin(std::string name, int pin_code);
};

#endif // ADMIN_H
