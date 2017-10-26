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

void add_task(Task *task_list)
{
//    Task new_task;
//    gets(new_task.description);
//    fflush(stdin);
//    scanf("%d", &new_task.priority);
//      fflush(stdin);
//    gets(new_task.checked.checked_display);
//      fflush(stdin);
//    scanf("%d", &new_task.checked.is_checked);
//      fflush(stdin);

    printf("Add task was called\n");

//    for (int i = 0; i < 10; i++) {
//        if (task_list[i].priority != 1) {
//            task_list[i] = new_task;
//            break;
//        }
//    }
}

void list_tasks(Task *task_list)
{
    printf("\t\t\t|TASK LIST|\nNum Chk Pri| Task Description\n=======================================================\n");
    for (int i = 0; i < 10; i++) {
            if (task_list[i].priority) {
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
    int command_nr;
    char *tokenizer;

    if (strcmp(input, "")) { // this if protects if an empty line is inputed
    tokenizer = strtok(input, " ");;
    strcpy(command, tokenizer);
    tokenizer = strtok(NULL, "\n");
    puts(tokenizer);
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
        add_task(task_list);
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


