#include "atmmachine.h"

ATMMachine::ATMMachine()
{

};

void ATMMachine::boot()
{
    cout << "ATM bootin." << endl;
    db = new DataBase;
};

ATMMachine::~ATMMachine()
{
    delete active_user;
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
            "Press 3 to: check the riches't man's balance\n"
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
        cout << "\nEntered command nr.: " << input_command << endl;

        switch (input_command) {
            case 1:
                cout << "case 1";
                break;
            case 2:
                cout << "case 2";
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
        cout << "\nEntered command nr.: " << input_command << endl;

        switch (input_command) {
            case 1:
                cout << "case 1";
                break;
            case 2:
                cout << "case 2";
                break;
            case 3:
                cout << "case 3";
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
        cout << "Login process had been started:\n";
        cout << "Please enter your username: " << endl;
        cin >> entered_username;

        for (unsigned int i = 0; i < db->get_user_vector().size(); ++i) {
            if (entered_username == db->get_user(i).get_name()) {
                cout << "user found at " << i << endl;
                active_user = &(db->get_user(i));
                cout << "active users's name: " << active_user->get_name();
                correct_username = true;
                break;
            }
        }
    } while (!correct_username);

    do {
        cout << "Please enter your pin code: " << endl;
        cin >> entered_pin;
        cout << "entered pin: " << entered_pin << endl;
        if (entered_pin == active_user->get_pin_code()) {
            correct_pin = true;
            cout << "i set pin to true";
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
}

