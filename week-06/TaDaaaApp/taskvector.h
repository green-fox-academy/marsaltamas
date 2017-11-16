#ifndef TASKVECTOR_H
#define TASKVECTOR_H
#include <vector>
using namespace std;
#include "tasks.h"

class TaskVector
{
    private:
        vector<Tasks> task_vector;

    public:
        void add_task_to_vector(Tasks task);
};

#endif // TASKVECTOR_H
