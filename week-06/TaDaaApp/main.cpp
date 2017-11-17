#include "task.h"
#include "opeartaionloop.h"

int main()
{
    OpeartaionLoop ol;
    ol.operation_prompt();
    cout << "main: " << ol.get_task(0).get_description();

    return 0;
}
