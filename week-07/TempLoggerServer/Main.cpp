#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <regex>
#include <cstring>

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

int get_command(vector<string> command_vector)
{
    string user_command;
    int commdand_id = -1;

    cout << "Please enter command: ";
    cin >> user_command;

    for (unsigned int i = 0; i < command_vector.size(); ++i) {
        if (command_vector.at(i) == user_command)
            commdand_id = i;
    }

    return commdand_id;
}

bool exit()
{
    cout << "Program quits." << endl;
    return false;
}

bool open_port(SerialPortWrapper *serial)
{
    serial->openPort();
    cout << "Port had been opened." << endl;
    return true;
}

int value_of_entry_segment(string *entry, size_t position1, size_t position2, string to_find)
{
    size_t lenght = 0;

    position2 = entry->find(to_find);
    lenght = position2 - position1;
    int value = atoi((entry->substr(position1, lenght)).c_str());
    entry->erase(position1, lenght + 1);

    return value;
}

/*
 * checks if the input string is a valid format
 * valid format is: "y.m.d h:m:s x"
 * where sequence is segmented by definite number of '.', ":" and " "
 * where each value must be within the specified range
 */
bool is_entry_valid(string entry)
{
    bool is_valid = false;

    // checking if format is correct
    regex reg("[0-9]{4}\\.[0-9]{1,2}\\.[0-9]{1,2} [0-9]{1,2}\\:[0-9]{1,2}\\:[0-9]{1,2} [-]{0,1}[0-9]{1,2}");

    if (regex_match(entry, reg)) { // if regex ok, checking the string sequentially by segment characters
            string point = ".";
            string double_point = ":";
            string space = " ";

            size_t position1 = 0;
            size_t position2 = entry.find(point);
            size_t lenght = position2 - position1;
            int year = atoi((entry.substr(position1, lenght)).c_str());
            entry.erase(position1, lenght + 1);

            if (year < 2018 && year > 1950) {

                int month = value_of_entry_segment(&entry, position1, position2, point);

                    if(month > 0 && month < 13) {

                        int day = value_of_entry_segment(&entry, position1, position2, space);
                         // check day (disregarding if month is 28, 30 or 31 days long
                        if(day > 0 && day < 32) {

                            int hour = value_of_entry_segment(&entry, position1, position2, double_point);

                            if (hour > -1 && hour < 24) {

                                int minute = value_of_entry_segment(&entry, position1, position2, double_point);

                                if (minute > -1 && minute < 60) {

                                    int second = value_of_entry_segment(&entry, position1, position2, space);

                                    if (second > -1 && second < 60) {

                                         int temperature = atoi(entry.c_str());

                                         if (temperature > -40 && temperature < 100) {
                                            cout << "valid entry" << endl;
                                            is_valid = true;
                                         }
                                    }
                                }
                            }
                         }
                    }
            }
    }

    return is_valid;
}

void start_stop_loggin(SerialPortWrapper *serial, bool port_open, vector<string> *log_vector)
{
    if (!port_open) {
        cout << "Please open port before starting to log." << endl;
        return;
    }

    string entry;

    cout << "Logging had been started. Press \"s\" to stop logging." << endl;

    // clear port's log
    do {
        serial->readLineFromPort(&entry);
    } while (entry.length() > 0);

    for (;;) {
        serial->readLineFromPort(&entry);
        if (entry.length() > 0){
            cout << entry << endl;
            if (is_entry_valid(entry))
                log_vector->push_back(entry);
        }

        if(kbhit()) {
            if (getch() == 's') // quits loop if 's' pressed
                break;
        }
    }
}

bool close_port(SerialPortWrapper *serial)
{
    serial->closePort();
    cout << "Port been closed." << endl;

    return false;
}

void print_list_handled_vector(vector<string> log_vector)
{
    cout << "Listing contents of the log on screen: " << endl;

    for (unsigned int i = 0; i < log_vector.size(); ++i) {
        cout << "Record " << i << ": " << log_vector.at(i) << endl;
    }
}

void run(vector<string> command_vector)
{
    bool keep_running = true;
    bool is_port_opened = false;
    SerialPortWrapper *serial = new SerialPortWrapper("COM3", 115200);
    vector<string> log_vector;

    while (keep_running) {

        switch (get_command(command_vector)) {
            case PRINT_MENU:
                print_menu();
                break;
            case OPEN_PORT:
                is_port_opened = open_port(serial);
                break;
            case START_STOP_LOGGIN:
                start_stop_loggin(serial, is_port_opened, &log_vector);
                break;
            case CLOSE_PORT:
                is_port_opened = close_port(serial);
                break;
            case LIST_HANDLED_VECTOR:
                print_list_handled_vector(log_vector);
                break;
            case CLEAR_SCREEN:
                system("cls");
                break;
            case EXIT:
                keep_running = exit();
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
