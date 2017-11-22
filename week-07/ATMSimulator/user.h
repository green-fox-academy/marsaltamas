#ifndef USER_H
#define USER_H

#include "define.h"

#include <string>
using namespace std;

class User
{
    public:

    protected:
        std::string name;
        int pin_code;
        int login_tries;
        int prevelage;
};

#endif // USER_H
