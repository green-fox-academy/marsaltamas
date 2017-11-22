#include "user.h"


 string User::get_name()
 {
     return name;
 };

 void User::set_name(string new_name)
 {
     name = new_name;
 };

int User::get_prevelage()
{
    return prevelage;
}

int User::get_login_tries()
{
    return login_tries;
}

int User::get_pin_code()
{
    return pin_code;
}

void User::decr_login_tries(int num){
    login_tries-= num;
}
