#include "temperaturedatabase.h"

TemperatureDatabase::TemperatureDatabase()
{
    // will load the database from file
}

TemperatureDatabase::~TemperatureDatabase()
{
    // will save the data to file
}

void TemperatureDatabase::process_string_log(string entry)
{
    istringstream i_stream(entry);
    tm time_data_sequence;
    int temperature;

    i_stream << strptime(entry.c_str(), "%Y.%m.%d %H:%M:%S", &time_data_sequence)
             << temperature;

    if (i_stream.fail())
        throw "Error transforming string to data log entry.\n";

    // no need to check temp and other ranges as already been validated

    valid_log_entry_t vlet;
    vlet.timestamp = mktime(&time_data_sequence);
    vlet.temperature = temperature;

    validated_data_log.push_back(vlet);
}
