#include "prototypes.h"

/* OPERATION
 * checking for existing txt file
 * if exists, reading in txt and uploading task_list array
 * printing usage
 * operation_prompt to read input line and forward it to input_processor
 * input_processor processes input until first space, and calls proper command, or sends error message
 * command takes input lie as argument and processes it further, executing command, or sending error message
 * control back to op_prompt
 */

 /* TODO
  * set up input processor for reading command
  * set up TASK struct - how to track task items quantity
  * add task function
  * list task function
  * file writing
  * file reading
  * etc
  */


int main()
{
    Task test_task = {"task 1", 1, "[x]", 1, TRUE};
    Task test_task2 = {"task 2", 1, "[x]", 1, TRUE};
    Task test_task3 = {"task 3", 1, "[x]", 1, TRUE};
    task_list[0] = test_task;
    task_list[1] = test_task2;
    task_list[2] = test_task3;
    //add_task(task_list);
    //add_task(task_list);
    //list_tasks(task_list);

    print_usage();

    return 0;
}

