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
  * error handling:
  *             - file opening and reading
  * functionalize duplicated code
  * add comments
  * structure headers
  */


int main()
{
    // dummy tasks for testing
    Task test_task1 = {"task 1", 0, "[ ]", FALSE, TRUE};
    Task test_task2 = {"task 2", 5, "[ ]", FALSE, TRUE};
    Task test_task3 = {"task 3", 5, "[X]", TRUE, TRUE};
    Task test_task4 = {"task 4", 0, "[X]", TRUE, TRUE};
    Task test_task5 = {"task 5", 5, "[ ]", FALSE, TRUE};
    Task test_task6 = {"task 6", 5, "[ ]", FALSE, TRUE};
    Task test_task7 = {"task 7", 2, "[ ]", FALSE, TRUE};
    Task test_task8 = {"task 8", 3, "[ ]", FALSE, TRUE};
    Task test_task9 = {"task 9", 3, "[ ]", FALSE, TRUE};
    //Task test_task10 = {"task 10", 5, "[ ]", 1, TRUE};

    task_list[0] = test_task1;
    task_list[1] = test_task2;
    task_list[2] = test_task3;
    task_list[3] = test_task4;
    task_list[4] = test_task5;
    task_list[5] = test_task6;
    task_list[6] = test_task7;
    task_list[7] = test_task8;
    task_list[8] = test_task9;
    //task_list[9] = test_task10;

    print_usage();

    return 0;
}

