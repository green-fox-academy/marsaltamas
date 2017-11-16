#include "operationloop.h"
#include "screentemplate.h"
#include "inputprocessor.h"

void OperationLoop::operationPrompt()
{
    ScreenTemplate st;
    st.print_header();
    st.print_foot();
    InputProcessor ip;
    ip.get_input();

}

void OperationLoop::inputProcessor()
{

}
