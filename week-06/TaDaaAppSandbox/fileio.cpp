#include "fileio.h"

void FileIO::write_to_file(vector<Task> *task_vector_pointer)
{
    this->task_vector_pointer = task_vector_pointer;
    ofstream out_file;
    string file_path = "fileToRead.txt";

    out_file.open(file_path, ios::out | ios::trunc);

    for (unsigned int i = 0; i < task_vector_pointer->size(); ++i) {
        out_file << task_vector_pointer->at(i).get_description() << endl;
        out_file << task_vector_pointer->at(i).get_checked_display() << endl;
        out_file << task_vector_pointer->at(i).get_priority() << endl;
    }

    out_file.close();
}

void FileIO::read_from_file(vector<Task> *task_vector_pointer)
{
    this->task_vector_pointer = task_vector_pointer;
    ifstream in_file;
    string file_path = "fileToRead.txt";
    string buffer;
    int priority;

    in_file.open(file_path, ios::in);

    for (unsigned int i = 0; i < task_vector_pointer->size(); ++i) {
        getline(in_file, buffer);
        cout << "buffer at " << i << " " << buffer << endl;
        task_vector_pointer->at(i).set_description(buffer);

        getline(in_file, buffer);
        cout << "buffer at " << i << " " << buffer << endl;
        task_vector_pointer->at(i).set_checked_display(buffer);

        getline(in_file, buffer);
        cout << "buffer at " << i << " " << buffer << endl;
        istringstream(buffer) >> priority;
        task_vector_pointer->at(i).set_priority(priority);
    }

    in_file.close();
}
