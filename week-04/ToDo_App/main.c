#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct Task{
    char description[100];
    int priority;
    struct Checked {
        char checked_display[4];
        int is_checked;
    } checked;
    struct Task *next;
} Task;

void print_usage(void);

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
}
