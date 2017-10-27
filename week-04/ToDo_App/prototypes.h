#ifndef PROTOTYPES_H
#define PROTOTYPES_H
#define COMMANDS 11
#define TRUE 1
#define FALSE 0

typedef enum Commands {
    A,   //0
    WR,  //1
    RD,  //2
    L,   //3
    E,   //4
    RM,  //5
    C,   //6
    P,   //7
    LPRI,  //8
    X,   //9
    CL   //10
} Commands;

extern char commands_array[COMMANDS][4];

typedef struct Task {
    char description[100];
    int priority;
    char checked_display[4];
    int is_checked;
    int active;
} Task;

Task task_list[10];

void print_usage(void);
void operation_prompt(void);
void input_processor(char input[]);
void add_task(Task *task_list, char input[]);
void add_task_pri(char input[]);
void list_tasks(Task *task_list);
void list_by_prior(void);
void clear_screen(void);
void exit_program(void);
void check_task(char input[]);
void empty_list(void);
void remove_task(char input[]);
void is_list_empty(void);
#endif // PROTOTYPES_H
