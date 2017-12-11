#ifndef TEMPERATUREDATABASE_H
#define TEMPERATUREDATABASE_H

#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <time.h>
#include "define.h"
#include <iostream>

using namespace std;

class TemperatureDatabase
{
    public:
        TemperatureDatabase();
        ~TemperatureDatabase();
        void print_data_log();
        vector<valid_log_entry_t*> validated_data_log_vector;
        // vector<packed_data_line_t*> packed_data_line_vector; unused version
        // void print_data_log_timestamp(); unused version

    private:

};

#endif // TEMPERATUREDATABASE_H
