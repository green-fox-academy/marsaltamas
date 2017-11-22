#include "atmmachine.h"
#include "customer.h"
#include <stdexcept>

ATMMachine::ATMMachine()
{

};

void ATMMachine::boot()
{
    db = new DataBase;
};

ATMMachine::~ATMMachine()
{
    delete db;
};

void ATMMachine::run()
{
    int mode = login();
    operation_prompt(mode);
};

void ATMMachine::print_customer_menu()
{
    cout <<
            "ATM SIMULATOR CORP.\n"
            "Press 1 to: withdraw money\n"
            "Press 2 to: check your balance\n"
            "Press 3 to: print menu\n"
            "Press 4 to: exit\n";
};

void ATMMachine::print_admin_menu()
{
    cout <<
            "ATM SIMULATOR CORP.\n"
            "Press 1 to: check machine's balance\n"
            "Press 2 to: add money to ATM\n"
            "Press 3 to: check the riches't person's balance\n"
            "Press 4 to: print menu\n"
            "Press 5 to: exit\n";
};

void ATMMachine::customer_mode()
{
    int input_command;
    print_customer_menu();
    bool keep_loopin = true;

    while (keep_loopin) {
        cout << "Please enter your command: ";
        cin >> input_command;

        switch (input_command) {
            case 1:
                withdraw();
                break;
            case 2:
                check_balance();
                break;
            case 3:
                print_customer_menu();
                break;
            case 4:
                keep_loopin = false;
                break;
            default:
                cout << "Invalid command.\n";
                break;
        }
    }
};

void ATMMachine::admin_mode()
{
    int input_command;
    print_admin_menu();
    bool keep_loopin = true;

    while (keep_loopin) {
        cout << "Please enter your command: ";
        cin >> input_command;

        switch (input_command) {
            case 1:
                db->check_atm_balance();
                break;
            case 2:
                db->top_up_amount_of_cash_in_atm();
                break;
            case 3:
                who_is_the_richest();
                break;
            case 4:
                print_admin_menu();
                break;
            case 5:
                keep_loopin = false;
                break;
            default:
                cout << "Invalid command.\n";
                break;
        }
    }
};


void ATMMachine::operation_prompt(int mode)
{
    if (mode == CUSTOMER) {
        customer_mode();
    } else if (mode == ADMINISTRATOR) {
        admin_mode();
    } else {
        cout << "Login failed. Please contact the bank to enable your account again." << endl;
    }
}

int ATMMachine::login()
{
    string entered_username;
    int entered_pin;
    bool correct_username = false;
    bool correct_pin = false;

    do {
        cout << "Please enter your username: " << endl;
        cin >> entered_username;

        for (unsigned int i = 0; i < db->get_user_vector().size(); ++i) {
            if (entered_username == db->get_user(i)->get_name()) {
                active_user = db->get_user(i);
                correct_username = true;
                break;
            }
        }
    } while (!correct_username);

    do {
        cout << "Please enter your pin code: " << endl;
        cin >> entered_pin;
        if (entered_pin == active_user->get_pin_code()) {
            correct_pin = true;;
            break;
        } else {
            active_user->decr_login_tries(1);
        }
    } while (active_user->get_login_tries() > 0);

    if (active_user->get_prevelage() == CUSTOMER && correct_pin) {
        return CUSTOMER;
    }
    else if (active_user->get_prevelage() == ADMINISTRATOR && correct_pin)
        return ADMINISTRATOR;
    else {
        return FAILED_LOGIN;
    }
};

void ATMMachine::quit_routine()
{
    cout << "ATM quits operation." << endl;
    db->save_to_file("file.txt");
}

void ATMMachine::withdraw()
{
    int to_withdraw;
    cout << "Please enter amount to withdraw: ";
    cin >> to_withdraw;
    try {
        if (to_withdraw < 1000)
            throw TOO_LOW_WITHDRAWAL;
        else if (to_withdraw > db->get_amount_of_cash_in_atm())
            throw OUT_OF_CASH;
        else if (to_withdraw > active_user->get_balance())
            throw TOO_LOW_BALANCE;

        active_user->set_balance(-to_withdraw);
        cout << "After withdrawal your balance is: " << active_user->get_balance() << endl;
    } catch (int i) {
        if (i == TOO_LOW_WITHDRAWAL)
            cout << "Transaction rejected. Minimum withdrawal is 1000 unites." << endl;
        else if (i == OUT_OF_CASH)
            cout << "We apologize. There is not enough money in the ATM to process your transaction. "
                    "Operator had been notified" << endl;
        else if (i == TOO_LOW_BALANCE)
            cout << "Transaction rejected. Your balance lacks sufficient founds." << endl;
    };

}

void ATMMachine::check_balance()
{
    cout << "Your have currently " << active_user->get_balance() << " units available." << endl;
}

void ATMMachine::who_is_the_richest()
{
    int highest_balance = INT_MIN;
    int pos_of_richest;

    for (unsigned int i = 0; i < db->get_user_vector().size(); ++i) {
        if (db->get_user(i)->get_prevelage() == CUSTOMER && db->get_user(i)->get_balance() > highest_balance) {
            pos_of_richest = i;
            highest_balance = db->get_user(i)->get_balance();
        }
    }

    cout << "The richest person of this ATM is " << db->get_user(pos_of_richest)->get_name();
    cout << ". And has a balance of " << highest_balance << " units." << endl;
}
