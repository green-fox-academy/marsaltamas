#include "fileio.h"

FileIO::FileIO(string file_path, TemperatureDatabase *tdb)
{
    this->file_path = file_path;
}

void FileIO::save_data_to_file()
{
    ofstream out_to_file;
    out_to_file.open(file_path, ios::out);

    for (int i = 0; i < 10; ++i) {
        out_to_file << "teszt write out" << endl;
    }

    out_to_file.close();
}

void FileIO::read_data_from_file(string file_path, TemperatureDatabase *tdb)
{
    ifstream in_from_file;
    in_from_file.open(file_path, ios::in);
    int size;

    in_from_file >> size;

    for (int i = 0; i < size; ++i) {
        valid_log_entry_t *nvle = new valid_log_entry_t;
        in_from_file >>  nvle->year;
        tdb->validated_data_log_vector.push_back(nvle);
    }

    in_from_file.close();
}
