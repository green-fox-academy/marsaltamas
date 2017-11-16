/* OPERATION
 * printing user screen according the layout template, including tasks as in vector
 * operation_prompt to read input line and forward it to input_processor
 * input_processor processes input until first space, and calls proper command, or sends error message
 * command takes input line as argument and processes it further, executing command, or sending error message
 * control back to op_prompt
 *
 * Classes:
 * - Command class
 * - Printing class
 * - IO class
 * - Task data class
 */

#include "screentemplate.h"
#include "operationloop.h"

using namespace std;

int main()
{
    OperationLoop ol;
    ol.operationPrompt();

    return 0;
}
