#ifndef TEMPERATUREDATABASE_H
#define TEMPERATUREDATABASE_H

#include <string>
#include <vector>
using namespace std;


class TemperatureDatabase
{
    public:
        TemperatureDatabase(vector<string> log_vector);
        ~TemperatureDatabase();

    private:
        typedef struct valid_log_entry {
            long timestamp;
            int temperature;
            } valid_log_entry_t;
        vector<valid_log_entry_t> log;
};

#endif // TEMPERATUREDATABASE_H
