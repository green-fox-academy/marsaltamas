#include "atmmachine.h"

ATMMachine::ATMMachine()
{
    boot();
    while (operation_prompt(login())) {

    }
    quit_routine();
};

void ATMMachine::boot()
{
  cout << "ATM bootin." << endl;
  DataBase load_db;
  db = load_db;
};

void ATMMachine::print_menu()
{
    cout <<
            "ATM SIMULATOR CORP.\n"
            "Press 1 to: withdraw money\n"
            "Press 2 to: check your balance\n"
            "Press 3 to: print menu\n"
            "Press 4 to: exit\n";
};

bool ATMMachine::operation_prompt(int mode)
{
    int input_command;

    if (mode == CUSTOMER) {
    cout << "customer mode started" << endl;
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
            cout << "case 4";
            return false;
        default:
            cout << "default";
    }

        return true;

    } else if (mode == ADMINISTRATOR) {
        cout << "admin mode started." << endl;
    }
}

int ATMMachine::login()
{
    string entered_username;
    int entered_pin;
    int operation_mode;

    cout << "Login process had been started:\n";
    cout << "Please enter your username: " << endl;
    cin >> entered_username;
    cout << "Please enter your pin code: " << endl;
    cin >> entered_pin;

    cout << entered_username << endl;
    cout << entered_pin << endl;

    return operation_mode;

};

void ATMMachine::quit_routine()
{
    cout << "ATM quits operation." << endl;
}
