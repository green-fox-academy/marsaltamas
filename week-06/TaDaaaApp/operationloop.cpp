#include "operationloop.h"
#include "screentemplate.h"
#include "inputprocessor.h"

void OperationLoop::operationPrompt()
{
    ScreenTemplate st;
    st.print_header();
    //printing list of tasks
    st.print_foot();
    InputProcessor ip;
    ip.command_selector(ip.get_input()); //getting input as string and passing it to tokenizer
}
