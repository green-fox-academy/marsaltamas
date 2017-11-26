#ifndef FILEIO_H
#define FILEIO_H

#include "temperaturedatabase.h"
#include <fstream>
#include "define.h"

class FileIO
{
    public:
        FileIO(string file_path, TemperatureDatabase *tdb);
        void save_data_to_file();
        void read_data_from_file(string file_path, TemperatureDatabase *tdb);
    private:
        string file_path;

};

#endif // FILEIO_H
