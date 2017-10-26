#ifndef PROTOTYPES_H
#define PROTOTYPES_H
#define COMMANDS 11
#define TRUE 1
#define FALSE 0

extern char commands_array[COMMANDS][4];
extern int task_list_size;

typedef struct Task {
    char description[100];
    int priority;
    char checked_display[4];
    int is_checked;
} Task;

Task task_list[10];

void print_usage(void);
void operation_prompt(void);
void input_processor(char input[]);
void add_task(Task *task_list);
void list_tasks(Task *task_list);
void clear_screen(void);
void exit_program(void);

#endif // PROTOTYPES_H