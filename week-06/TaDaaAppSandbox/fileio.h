#ifndef FILEIO_H
#define FILEIO_H

#include <fstream>
#include <locale>
#include <sstream>
#include "commands.h"

class FileIO
{
    public:
        void write_to_file(vector<Task> *task_vector_pointer);
        void read_from_file(vector<Task> *task_vector_pointer);
        vector<Task> *task_vector_pointer;

};

#endif // FILEIO_H
