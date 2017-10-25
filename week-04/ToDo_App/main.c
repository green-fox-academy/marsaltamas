#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define COMMANDS 9

typedef struct Task {
    char description[100];
    int priority;
    struct Checked {
        char checked_display[4];
        int is_checked;
    } checked;
    struct Task *next;
} Task;

void print_usage(void);
void operation_prompt(void);
void input_processor(char input[]);

char commands[COMMANDS][3] = {"-a", "-wr", "-rd", "-l", "-e", "-rm", "-c", "-p", "-lp"};

int main()
{
    print_usage();
    return 0;
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
            "-lp  Lists all the tasks by priority\n");

    operation_prompt();
}

void input_processor(char input[]){

    char command[4];
    char *tokenizer;

    tokenizer = strtok(input, " ");
    strcpy(command, tokenizer);

    printf("%s\n", command);

}

void operation_prompt(void)
{
    char input[100];

    input_processor(gets(input));
}


