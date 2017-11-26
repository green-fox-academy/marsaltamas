#include "temperaturedatabase.h"

TemperatureDatabase::TemperatureDatabase()
{
    // will load the database from file
}

TemperatureDatabase::~TemperatureDatabase()
{
    // will save the data to file
}

void TemperatureDatabase::print_data_log()
{

    for (unsigned int i = 0; i < validated_data_log_vector.size(); ++i) {

        cout << "Record nr." << i + 1 << ": ";
        cout << validated_data_log_vector.at(i)->year << ".";
        cout << validated_data_log_vector.at(i)->month << ".";
        cout << validated_data_log_vector.at(i)->day << " ";
        cout << validated_data_log_vector.at(i)->hour << ":";
        cout << validated_data_log_vector.at(i)->minute << ":";
        cout << validated_data_log_vector.at(i)->second << " ";
        cout << validated_data_log_vector.at(i)->temperature << endl;
    }
}

void TemperatureDatabase::print_data_log_timestamp()
{
    struct tm *time_format;
    char to_print[50];

    for (unsigned int i = 0; i < packed_data_line_vector.size(); ++i) {

        time_format = localtime(&(packed_data_line_vector.at(i)->time_stamp));
        strftime(to_print, 50, "%Y:%m:%d %H:%M:%S ", time_format);
        cout << "converted ts formatted: " << to_print << packed_data_line_vector.at(i)->temperature << endl;
    }
}
