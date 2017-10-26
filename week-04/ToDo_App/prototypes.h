#ifndef PROTOTYPES_H
#define PROTOTYPES_H

typedef struct Task {
    char description[100];
    int priority;
    struct Checked {
        char checked_display[4];
        int is_checked;
    } checked;
    //struct Task *next;
} Task;

void print_usage(void);
void operation_prompt(void);
void input_processor(char input[]);
void add_task(Task *task_list);
void list_tasks(Task *task_list);

#endif // PROTOTYPES_H
