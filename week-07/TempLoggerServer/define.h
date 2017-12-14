#ifndef DEFINE_H
#define DEFINE_H

typedef enum Months_enum {
    JAN =1,     //1
    FEB,        //2
    MAR,        //3
    APR,        //4
    MAY,        //5
    JUN,        //6
    JUL,        //7
    AUG,        //8
    SEP,        //9
    OCT,        //10
    NOV,        //11
    DEC         //12
    } e_months;

typedef enum Commands_enum {
    PRINT_MENU ,            //0
    OPEN_PORT,              //1
    START_STOP_LOGGIN,      //2
    CLOSE_PORT,             //3
    LIST_HANDLED_VECTOR,    //4
    CLEAR_SCREEN,           //5
    SET_PORT_NAME,          //6
    SAVE_TO_FILE,           //7
    READ_FROM_FILE,         //8
    AVG_TH_BY_DAYS,         //9
    MAX_TH_BY_DAYS,         //10
    MIN_TH_BY_DAYS,         //11
    AVG_TH_BY_TEMPERATURES, //12
    MAX_TH_BY_TEMPERATURES, //13
    MIN_TH_BY_TEMPERATURES, //14
    EXIT                    //15
    } e_commands;

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int temperature;
    int months_stamp;
    int seconds_stamp;
} valid_log_entry_t;

typedef struct {
    int temperature;
    time_t time_stamp;

} packed_data_line_t;

#endif // DEFINE_H

/*
 * this part can be used for parsing the command string of the submenus
 *
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    string command;
    int year, month, day;
    vector<int> command_vector(10);

    while (1) {

        cout << "Please enter your command: ";

        getline(cin, command);

        cout << "command was: " << command << endl;

        istringstream line_stream(command);

        char sep;
        line_stream >> year >> sep >> month >> sep >> day;

        if (line_stream.fail()) {
            cout << "bad format" << endl;
        } else {
            command_vector.at(0) = year;
            command_vector.at(1) = month;
            command_vector.at(2) = day;
            for (int i = 0; i < 3; ++i) {
                cout << command_vector.at(i) << endl;
            }
        }

    }


    return 0;
}
*/


/*
#include <iostream>

using namespace std;

/*
 * contains the number of days in a year
 * up to the given month, but excluding that month

const int _to_months_end[] = {
    0,
    0,   //       JAN
    31,  //       FEB
    59,  //28  // MAR
    90,  //31, // APR
    120, //30, // MAY
    151, //31, // JUN
    181, //30, // JUL
    212, //31, // AUG
    243, //31, // SEP
    273, //30, // OCT
    304, //31, // NOV
    334, //30  // DEC
    };

typedef enum Days_to_end {
    JAN =1,     //1
    FEB,        //2
    MAR,        //3
    APR,        //4
    MAY,        //5
    JUN,        //6
    JUL,        //7
    AUG,        //8
    SEP,        //9
    OCT,        //10
    NOV,        //11
    DEC         //12
    } e_months;

/*
 * converts years and months and returns them as seconds
 * considering 1972 as year 0
 * works for year from 1972

 int years_months_as_days(int year, int month)
{
    int as_days = 0;

    year = year - 1972;                 // remove 1972 to meet int ranges

    as_days = year * 365 + _to_months_end[month];

    if (year == 0 && month > FEB) {     // if year was 1972 and passed FEB, we add 1 as running year
        as_days++;
    } else if (year < 4 && year > 0) {  // if year was above 1972 and below 1976 there was 1 running year
        as_days++;
    } else if(month > FEB) {            // if year is above 1975, add 1 day for every FEB passed, including actual year
        as_days+= year / 4 + 1;
    } else {
        as_days+= year / 4;             // if current year has not passed 29 day FEB, add 1 day for every FEB passed, excluding actual year
    }

    return as_days * 24 * 3600;
}

int main()
{
    years_months_as_days(1972, 2);
    years_months_as_days(1972, 3);
    years_months_as_days(1973, 2);
    years_months_as_days(1973, 3);
    years_months_as_days(1975, 2);
    years_months_as_days(1975, 3);
    years_months_as_days(1976, 2);
    years_months_as_days(1976, 3);
    years_months_as_days(1980, 2);
    years_months_as_days(1980, 3);

    return 0;
}

*/

