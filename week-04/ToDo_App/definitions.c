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
}

void exit_program(void)
{
    exit(0);
}

void add_task(Task *task_list, char input[])
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

            for (int i = 0; i < 10; i++) {
                if (task_list[i].active != 1) {
                    task_list[i] = new_task;
                    break;
                }
            }
        } else
            printf("Invalid instruction. Enclose the task between \"...\".\n");
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
}

void list_by_prior(void)
{
    printf("\t\t\t|TASK LIST|\nNum Chk Pri| Task Description\n=======================================================\n");

    int pos = 0;
    Task temp_task;

    for (int i = 5; i > 0; i--) {
        for (int j = 0; j < 10; j++) {
            if (task_list[j].priority == i) {
                temp_task = task_list[pos];
                task_list[pos] = task_list[j];
                task_list[j] = temp_task;
                pos++;
            }
        }
    }



    for (int i = 0; i < 10; i++) {
            if (task_list[i].active == TRUE) {
                printf("%3d ", i +1);
                printf("%s\t", task_list[i].checked_display);
                printf(" %d | ", task_list[i].priority);
                printf("%s\n", task_list[i].description);
                printf("_______________________________________________________\n");
            }
    }
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

void write(char target_file[])
{
    printf("write was called.\n");

    char *reader = NULL;

    if(target_file[0] != 34) // 34 == "
        printf("Invalid instruction. Enclose the target file between \"...\".\n");
    else {
        target_file++; // dodge first dbl quot mark
        reader = strchr(target_file, 34);
        if (reader != NULL) {
            *reader = '\0';
        }
        else
            printf("Invalid instruction. Enclose the target file between \"...\".\n");
    }

    FILE *file_p;

    file_p = fopen(target_file, "w");

    fprintf(file_p, "\t\t\t|TASK LIST|\nNum Chk Pri| Task Description\n=======================================================\n");
    for (int i = 0; i < 10; i++) {
            if (task_list[i].active == TRUE) {
                fprintf(file_p, "%3d ", i + 1);
                fprintf(file_p, "%s\t", task_list[i].checked_display);
                fprintf(file_p, " %d | ", task_list[i].priority);
                fprintf(file_p, "%s\n", task_list[i].description);
                fprintf(file_p, "_______________________________________________________\n");
            }
    }

    fclose(file_p);
}

void read_from_file(char soruce_file[])
{
    printf("read was called.\n");

    char *reader = NULL;

    if(soruce_file[0] != 34) // 34 == "
        printf("Invalid instruction. Enclose the target file between \"...\".\n");
    else {
        soruce_file++; // dodge first dbl quot mark
        reader = strchr(soruce_file, 34);
        if (reader != NULL) {
            *reader = '\0';
        }
        else
            printf("Invalid instruction. Enclose the target file between \"...\".\n");
    }

    FILE *file_p;
    char buffer[57];
    int linecounter = 0;
    int i = 0;

    file_p = fopen(soruce_file, "r");

    while (fgets(buffer, 57, file_p)) {
        ++linecounter;
        if (linecounter > 3 && !(linecounter % 2)) {
            task_list[i].active = 1;
            if (buffer[5] == 'x') {
                task_list[i].is_checked = 1;
                strcpy(task_list[i].checked_display, "[x]");
            }
            task_list[i].priority = atoi(&buffer[9]);
            strcpy(task_list[i].description, &buffer[13]);
            i++;
        }
    }
    fclose(file_p);
}

void check_task(char input[])
{
    int task_nr = atoi(input);

    strcpy(task_list[task_nr - 1].checked_display, "[x]");
    task_list[task_nr -1].is_checked = TRUE;
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
}

void remove_task(char input[])
{
    int task_nr = atoi(input);

    for (int i = task_nr - 1; i < 10; i++) {
        task_list[i] = task_list[i + 1];
        if (task_list[i + 1].active == FALSE)
            break;
    }
}
