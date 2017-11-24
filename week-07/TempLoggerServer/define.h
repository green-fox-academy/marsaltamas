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
    EXIT                    //6
    } e_commands;

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int temperature;
} valid_log_entry_t;

#endif // DEFINE_H
