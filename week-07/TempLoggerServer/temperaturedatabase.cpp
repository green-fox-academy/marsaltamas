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
