#include "admin.h"

Admin::Admin(std::string name, int pin_code)
{
    this->name = name;
    this->pin_code = pin_code;
    this->login_tries = 1;
    prevelage = ADMINISTRATOR;
};
