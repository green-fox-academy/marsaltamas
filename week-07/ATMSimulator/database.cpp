#include "database.h"
#include <iostream>

DataBase::DataBase()
{
    // init test db
    users_vector.push_back(new Customer("Alan", 1111, 4500));
    users_vector.push_back(new Customer("Bale", 2222, 10000));
    users_vector.push_back(new Customer("Celane", 3333, 30000));
    users_vector.push_back(new Admin("Admin", 11111111));
    users_vector.push_back(new Admin("Baddmin", 22222222));
    amount_of_cash_in_atm = 5000;
};

int DataBase::get_amount_of_cash_in_atm()
{
    return amount_of_cash_in_atm;
};

void DataBase::top_up_amount_of_cash_in_atm()
{
    int to_add;
    cout << "Please enter how much your will to add: ";
    cin >> to_add;
    amount_of_cash_in_atm+= to_add;
};

User* DataBase::get_user(int i)
{
    return users_vector.at(i);
}

vector<User*> DataBase::get_user_vector()
{
    return users_vector;
}

void DataBase::check_atm_balance()
{
    cout << "There are " << amount_of_cash_in_atm << " unite in the ATM currently." << endl;
}

/* first we count the number of users and admins
 * as a header for reading the file later, we add the quantities
 * first we log out users's info
 * then admins' info
 */
void DataBase::save_to_file(string file_path)
{
    ofstream out_file_stream;
    out_file_stream.open(file_path, ios::out);
    int user_count = 0;
    int admin_count = 0;

    for (unsigned int i = 0; i < users_vector.size(); ++i) {
        if (is_user(i))
            user_count++;
    }

    admin_count = users_vector.size() - user_count;
    out_file_stream << user_count << endl;
    out_file_stream << admin_count << endl;

    for (unsigned int i = 0; i < users_vector.size(); ++i) {
            if (is_user(i)) {
                out_file_stream << get_user(i)->get_name() << endl;
                out_file_stream << get_user(i)->get_pin_code() << endl;
                out_file_stream << get_user(i)->get_balance() << endl;
                out_file_stream << CUSTOMER << endl;
            }
    }

    for (unsigned int i = 0; i < users_vector.size(); ++i) {
        if (!is_user(i)) {
            out_file_stream << get_user(i)->get_name() << endl;
            out_file_stream << get_user(i)->get_pin_code() << endl;
            out_file_stream << ADMINISTRATOR << endl;
        }
    }

    out_file_stream.close();
}

bool DataBase::is_user(int i)
{
    if (get_user(i)->get_prevelage() == 1)
        return true;
    else
        return false;
}
