#include <iostream>
#include <string>
#include <vector>

#include "SerialPortWrapper.h"


using namespace std;

typedef enum Commands_enum {
    PRINT_MENU ,            //0
    OPEN_PORT,              //1
    START_STOP_LOGGIN,      //2
    CLOSE_PORT,             //3
    LIST_HANDLED_VECTOR,    //4
    CLEAR_SCREEN,           //5
    EXIT                    //6
    } e_commands;

void print_port_info()
{
    vector<string> ports = SerialPortWrapper::listAvailablePorts();
    cout << "Number of found serial ports: " << ports.size() << endl;
    for (unsigned int i = 0; i < ports.size(); i++) {
        cout << "\tPort name: " << ports.at(i) << endl;
    }
}

void print_menu()
{
    cout <<
                "     Temperature Logger Application\n"
                "======================================\n"
                "Commands:\n"
                "h        Show command list\n"
                "o        Open port\n"
                "s        Start logging / Stop logging\n"
                "c        Close port\n"
                "l        List after error handling\n"
                "cls      Clear screen\n"
                "e        Exit from the program\n"
                "=====================================\n";
}


void log_temp()
{
    // connection

    SerialPortWrapper *serial = new SerialPortWrapper("COM3", 115200);
    serial->openPort();
    string line;
    while(1){
    serial->readLineFromPort(&line);
    if (line.length() > 0){
        cout << line << endl;
        }
    }
    serial->closePort();
}

int get_command(vector<string> command_vector)
{
    string user_command;
    int commdand_id = -1;

    cout << "Please enter command: ";
    cin >> user_command;

    cout << "Command was: " << user_command << endl;

    for (unsigned int i = 0; i < command_vector.size(); ++i) {
        if (command_vector.at(i) == user_command)
            commdand_id = i;
    }

    return commdand_id;
}


void run(vector<string> command_vector)
{
    bool keep_running = true;

    while (keep_running) {

        switch (get_command(command_vector)) {
            case 0:
                cout << "case 0" << endl;
                break;
            case 1:
                cout << "case 1" << endl;
                break;
            case 2:
                cout << "case 2" << endl;
                break;
            case 3:
                cout << "case 3" << endl;
                break;
            case 4:
                cout << "case 4" << endl;
                break;
            case 5:
                cout << "case 5" << endl;
                break;
            case 6:
                cout << "case 6" << endl;
                break;
            default:
                cout << "default" << endl;

        };
    }
}

vector<string> init_command_vector()
{
    vector<string> command_vector;

    command_vector.push_back("h");
    command_vector.push_back("o");
    command_vector.push_back("s");
    command_vector.push_back("c");
    command_vector.push_back("l");
    command_vector.push_back("cls");
    command_vector.push_back("e");

    return command_vector;
}

int main()
{
    vector<string> command_vector = init_command_vector();

    print_port_info();
    print_menu();
    run(command_vector);

    return 0;
}
