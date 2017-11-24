#include "functions.h"

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

bool is_between(int value, int min, int max)
{
    if (value > min && value < max)
        return true;
    else
        return false;
}

int value_of_entry_segment(string *entry, string to_find)
{
    size_t lenght = 0;
    size_t position1 = 0;

    size_t position2 = entry->find(to_find);
    lenght = position2 - position1;
    int value = atoi((entry->substr(position1, lenght)).c_str());
    entry->erase(position1, lenght + 1);

    return value;
}

bool is_day_valid(int year, int month, int day)
{
    bool is_valid = true;

    // 30 day months
    if ((month == APR ||
         month == JUN ||
         month == SEP ||
         month == NOV) &&
         day > 30) is_valid = false;

     if (month == FEB) {
        if (!year % 4 && day > 29) // running years
            is_valid = false;
        else if (day > 28)         // normal years, if febr is over 28 days in input data
            is_valid = false;      // input considered invalid
     }

    return is_valid;
}

/*
 * checks if the input string is a valid format
 * valid format is: "y.m.d h:m:s x"
 * where sequence is segmented by definite number of '.', ":" and " "
 * where each value must be within the specified range
 *
 * this function is turned out to be deprecated code
 * but i leave it here for memory, and as it also checks how many days a month can contain
 * also an implementation / refactor can be done to covert int values to tm type
 *
 * a compact solution for the same problem is implemented in the TemperatureDataBase class
 * and uses the stringstream and inbuilt time functions
 * this means that work flow contains unnecessary steps
 */
void validate_and_push_to_tdb(string entry, TemperatureDatabase *tdb)
{
    // checking if format is correct
    regex reg("[0-9]{4}\\.[0-9]{1,2}\\.[0-9]{1,2} [0-9]{1,2}\\:[0-9]{1,2}\\:[0-9]{1,2} [-]{0,1}[0-9]{1,3}");

    if (regex_match(entry, reg)) { // if regex ok, checking the string sequentially by segment characters
            string point = ".";
            string double_point = ":";
            string space = " ";
            int year;
            int month;
            int day;
            int hour;
            int minute;
            int second;
            int temperature;

            /*
             * sequence checks each segment of the text (which is already in correct format)
             * 'if' steps are passed only if the value of given segment of the text
             * is between the specified boundaries
             */
            if (is_between((year = value_of_entry_segment(&entry, point)), 1900, 2018)) {

                if (is_between((month = value_of_entry_segment(&entry, point)), 0, 13))  {

                    if (is_between((day = value_of_entry_segment(&entry, space)), 0, 32))  {
                        // checks if there are no more days in a month than allowed, eg. no 29 days in febr in non running years
                        if (is_day_valid(year, month, day)) {

                            if (is_between((hour = value_of_entry_segment(&entry, double_point)), -1, 24))  {

                                if (is_between((minute = value_of_entry_segment(&entry, double_point)), -1, 60))  {

                                    if (is_between((second = value_of_entry_segment(&entry, space)), -1, 60))  {

                                         if (is_between((temperature = atoi(entry.c_str())), -50, 200))  {
                                            cout << "valid entry" << endl;
                                            valid_log_entry_t *vle_pointer = new valid_log_entry_t;
                                            vle_pointer->year = year;
                                            vle_pointer->month = month;
                                            vle_pointer->day = day;
                                            vle_pointer->hour = hour;
                                            vle_pointer->minute = minute;
                                            vle_pointer->second = second;
                                            vle_pointer->temperature = temperature;
                                            tdb->validated_data_log_vector.push_back(vle_pointer);
                                         }
                                    }
                                }
                            }
                         }
                    }
                }
            }
    }
}

void start_stop_loggin(SerialPortWrapper *serial, bool port_open, vector<string> *log_vector, TemperatureDatabase *tdb)
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
            validate_and_push_to_tdb(entry, tdb);
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

void run(vector<string> command_vector, TemperatureDatabase *tdb)
{
    bool keep_running = true;
    bool is_port_opened = false;
    SerialPortWrapper *serial = new SerialPortWrapper("COM6", 115200);
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
                start_stop_loggin(serial, is_port_opened, &log_vector, tdb);
                break;
            case CLOSE_PORT:
                is_port_opened = close_port(serial);
                break;
            case LIST_HANDLED_VECTOR:
                tdb->print_data_log();
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

