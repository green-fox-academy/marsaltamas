#ifndef TEMPERATUREDATABASE_H
#define TEMPERATUREDATABASE_H

#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <time.h>

using namespace std;


class TemperatureDatabase
{
    public:
        TemperatureDatabase();
        ~TemperatureDatabase();
        void process_string_log(string entry);

    private:
        typedef struct valid_log_entry {
            long timestamp;
            int temperature;
            } valid_log_entry_t;
        vector<valid_log_entry_t> validated_data_log;
};

#endif // TEMPERATUREDATABASE_H
