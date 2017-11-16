#ifndef OPERATIONLOOP_H
#define OPERATIONLOOP_H
#include <string>
#include <istream>
#include <stdlib.h>
#include <vector>
#include "task.h"

using namespace std;


class OperationLoop {
    public:
        void operationPrompt();

    private:
        vector<Task> task_vector;


};

#endif // OPERATIONLOOP_H
