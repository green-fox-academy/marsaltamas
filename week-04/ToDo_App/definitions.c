#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "prototypes.h"

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
    operation_prompt();
}
void exit_program(void){
    exit(0);
}

void add_task(Task *task_list, char input[])
{
    Task new_task;
    char *reader = NULL;
    printf("Add task was called\n");
    printf("line got to addtask: %s\n", input);

    if(input[0] != 34) // 34 == "
        printf("Invalid instruction. Enclose the task between parenthesis.\n");
    else {
        input++;
        reader = strchr(input, 34);
        if (reader != NULL) {
            *reader = '\0';
            strcpy(new_task.description, input);
            strcpy(new_task.checked_display, "[ ]");
            new_task.is_checked = 0;
            new_task.priority = 0;
            new_task.active = TRUE;
        }


    }

    for (int i = 0; i < 10; i++) {
        if (task_list[i].active != 1) {
            task_list[i] = new_task;
            break;
        }
    }
    operation_prompt();
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
    operation_prompt();
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
    case 0:
        add_task(task_list, input);
        break;
    case 3:
        list_tasks(task_list);
        break;
    case 9:
        exit_program();
        break;
    case 10:
        clear_screen();
        break;
   default:
        printf("Invalid instruction.\n");
    }

    operation_prompt();
}


