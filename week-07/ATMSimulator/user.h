#ifndef USER_H
#define USER_H

#include "define.h"

#include <string>
using namespace std;

class User
{
    public:
        string get_name();
        void set_name(string new_name);
        int get_prevelage();
        int get_login_tries();
        void decr_login_tries(int num);
        int get_pin_code();
        virtual void set_balance(int change){};
        virtual int get_balance(){return 0;}; // set up for customer only

    protected:
        std::string name;
        int pin_code;
        int login_tries;
        int prevelage;
};

#endif // USER_H
