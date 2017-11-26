#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <regex>
#include <cstring>

#include "SerialPortWrapper.h"
#include "temperaturedatabase.h"
#include "define.h"
#include "fileio.h"

void print_port_info();
void print_menu();
int get_command(vector<string> command_vector);
bool exit();
bool open_port(SerialPortWrapper *serial);
bool is_between(int value, int min, int max);
int value_of_entry_segment(string *entry, string to_find);
bool is_day_valid(int year, int month, int day);
void validate_and_push_to_tdb(string entry, TemperatureDatabase *tdb);
void start_stop_loggin(SerialPortWrapper *serial, bool port_open, vector<string> *log_vector, TemperatureDatabase *tdb);
bool close_port(SerialPortWrapper *serial);
void run(vector<string> command_vector, TemperatureDatabase *tdb);
void save_to_file(string file_path, TemperatureDatabase *tdb);
void read_from_file(string file_path, TemperatureDatabase *tdb);

vector<string> init_command_vector();



#endif // FUNCTIONS_H
