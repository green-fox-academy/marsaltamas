#ifndef OPEARTAIONLOOP_H
#define OPEARTAIONLOOP_H

#include "task.h"
#include <vector>
#include <iostream>
#include "inputprocessor.h"

class OpeartaionLoop
{
    public:
        void operation_prompt();
        Task get_task(int pos);

    private:
        vector<Task> task_vector;
};

#endif // OPEARTAIONLOOP_H
