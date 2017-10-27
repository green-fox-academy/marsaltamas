#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "prototypes.h"
#include "fileio.h"

void operation_prompt(void)
{
    char input[100] = " ";

    printf("Please enter instructions:\n");

    input_processor(gets(input));
}

void print_usage(void)
{
    printf( "           Todo application\n"
            "========================================\n"
            "Commands:\n"
            "-a   Adds a new task\n"
            "-wr  Write current todos to file\n"
            "-rd  Read todos from a file\n"
            "-l   Lists all the tasks\n"
            "-e   Empty the list\n"
            "-rm  Removes a task\n"
            "-c   Completes a task\n"
            "-p   Add priority to a task\n"
            "-lp  Lists all the tasks by priority\n"
            "-x   Exit\n"
            "-cl   Clear screen\n");

    operation_prompt();
}

void clear_screen(void)
{
    system("cls");
}

void exit_program(void)
{
    exit(0);
}

void add_task(Task *task_list, char input[])
{
    Task new_task;
    char *reader = NULL;

    if(input[0] != 34) { // 34 == "
        printf("Invalid instruction. Enclose the task between \"...\".\n");
    } else {
        input++; // dodge first dbl quot mark
        reader = strchr(input, 34);
        if (reader != NULL) {
            *reader = '\0';
            strcpy(new_task.description, input);
            strcpy(new_task.checked_display, "[ ]");
            new_task.is_checked = 0;
            new_task.priority = 0;
            new_task.active = TRUE;

            if (task_list[9].active == TRUE) {
                printf("Can not add more tasks, the list is full.\n");
            } else {
                for (int i = 0; i < 10; i++) {
                    if (task_list[i].active != TRUE) {
                        task_list[i] = new_task;
                        break;
                    }
                }
            }
        } else {
            printf("Invalid instruction. Enclose the task between \"...\".\n");
        }
    }
}

void list_tasks(Task *task_list)
{
    printf("\t\t\t|TASK LIST|\nNum Chk Pri| Task Description\n=======================================================\n");
    for (int i = 0; i < 10; i++) {
            if (task_list[i].active == TRUE) {
                printf("%3d ", i +1);
                printf("%s\t", task_list[i].checked_display);
                printf(" %d | ", task_list[i].priority);
                printf("%s\n", task_list[i].description);
                printf("_______________________________________________________\n");
            }
    }
    is_list_empty();
}

//checking if list contains active tasks
void is_list_empty(void)
{
    int flag = FALSE;
    for (int i = 0; i < 10; i++) {
        if (task_list[i].active == TRUE)
            flag = TRUE;
    }
    if (!flag)
        printf("===================List is empty now.==================\n"
               "=======Now you have time for worrying about exam!======\n"
               "=======================================================\n");
}
// same as list task, only a sorting alg added at the beginning.
void list_by_prior(void)
{
    int pos = 0;
    Task temp_task;

    for (int i = 5; i > 0; i--) {
        for (int j = pos; j < 10; j++) {
            if (task_list[j].priority == i) {
                temp_task = task_list[pos];
                task_list[pos] = task_list[j];
                task_list[j] = temp_task;
                pos++;
            }
        }
    }
    list_tasks(task_list);
}

void input_processor(char input[])
{
    char command[4] = " ";
    int command_nr = -1;
    char *tokenizer;

    if (strcmp(input, "")) { // this if protects if an empty line is inputed
        tokenizer = strtok(input, " ");
        if(tokenizer != NULL) { //reading further parts of input
            strcpy(command, tokenizer);
            tokenizer = strtok(NULL, ""); //reads the entire line left if it is not empty
            if(tokenizer != NULL) //copy the entire line left if it is not empty
                strcpy(input, tokenizer);
        }
    }

    // call for command selector
    for (int i = 0; i < COMMANDS; i++) {
        if (!strcmp(command, commands_array[i])) {
            command_nr = i;
            break;
        }
    }

    switch (command_nr) {
    case A:
        add_task(task_list, input);
        break;
    case WR:
        write(input);
        break;
    case RD:
        read_from_file(input);
        break;
    case L:
        list_tasks(task_list);
        break;
    case E:
        empty_list();
        break;
    case RM:
        remove_task(input);
        break;
    case C:
        check_task(input);
        break;
    case P:
        add_task_pri(input);
        break;
    case X:
        exit_program();
        break;
    case LPRI:
        list_by_prior();
        break;
    case CL:
        clear_screen();
        break;
   default:
        printf("Invalid instruction.\n");
    }
    operation_prompt();
}

void check_task(char input[])
{
    int task_nr = atoi(input);

    if (task_nr < 1 || task_nr > 10) {
        printf("Your provided an invalid index.\n");
    } else if (task_list[task_nr].active == FALSE) {
        printf("There is no active task at that position.\n");
    } else if (task_list[task_nr].is_checked == TRUE) {
        printf("This task had already been checked.\n");
    } else {
        strcpy(task_list[task_nr - 1].checked_display, "[x]");
        task_list[task_nr -1].is_checked = TRUE;
    }
}

void empty_list(void)
{
    for (int i = 0; i < 10; i++) {
        task_list[i].active = FALSE;
        strcpy(task_list[i].checked_display, "[ ]");
        strcpy(task_list[i].description, "");
        task_list[i].priority = 0;
        task_list[i].is_checked = FALSE;
    }

    printf("List is empty now. Now you have time for worrying about exam!\n\n");
}

void remove_task(char input[])
{
    int task_nr = atoi(input);

    if (task_nr < 1 || task_nr > 10) {
        printf("Your provided an invalid index.\n");
    } else if (task_list[task_nr].active == FALSE) {
        printf("There is no active task at that position.\n");
    } else {
        for (int i = task_nr - 1; i < 10; i++) {
            task_list[i] = task_list[i + 1];
            if (task_list[i + 1].active == FALSE)
                break;
        }
    }
}


void add_task_pri(char input[])
{
    Task new_task;
    char *reader = NULL;

    if(input[0] != 34) // 34 == "
        printf("Invalid instruction. Enclose the task between \"...\".\n");
    else {
        input++; // dodge first dbl quot mark
        reader = strchr(input, 34);
        if (reader != NULL) {
            *reader = '\0';
            strcpy(new_task.description, input);
            strcpy(new_task.checked_display, "[ ]");
            new_task.is_checked = 0;
            new_task.priority = 0;
            new_task.active = TRUE;

            if (task_list[9].active == TRUE) {
                    printf("Can not add more tasks, the list is full.\n");
            } else {
                reader++;

                if (reader != NULL && atoi(reader))
                    new_task.priority = atoi(reader);
                else
                    printf("Your task had been added, but w/o priority due to invalid parameter.\n");

                for (int i = 0; i < 10; i++) {
                    if (task_list[i].active != 1) {
                        task_list[i] = new_task;
                        break;
                    }
                }
            }
        } else {
            printf("Invalid instruction. Enclose the task between \"...\".\n");
        }
    }
}
