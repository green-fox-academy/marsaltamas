#ifndef PROTOTYPES_H
#define PROTOTYPES_H
#define COMMANDS 11
#define TRUE 1
#define FALSE 0

// enum for commands
typedef enum Commands {
    A,   //0
    WR,  //1
    RD,  //2
    L,   //3
    E,   //4
    RM,  //5
    C,   //6
    P,   //7
    LPRI,//8
    X,   //9
    CL   //10
} Commands;

// array holding commands
extern char commands_array[COMMANDS][4];

typedef struct Task {
    char description[100];
    int priority;
    char checked_display[4];
    int is_checked;
    int active; // indicating if task is to be considered during list operations
} Task;

// array for holding tasks
Task task_list[10];

// prints start screen, then enters operation
void print_usage(void);

// collects user input from user
void operation_prompt(void);

/* takes input, which is being interpreted as command and it's parameters
 * calls proper function based on command or send error message
 */
void input_processor(char input[]);

// takes an array of Tasks and adds a task to is, based on input char array
void add_task(Task *task_list, char input[]);

// add_task subversion, capable of setting priority as well based on input array
void add_task_pri(char input[]);

// takes an array of tasks and prints elements on screen
void list_tasks(Task *task_list);

// list_tasks subversion, printing tasks on screen in descending priority order
void list_by_prior(void);

void clear_screen(void);
void exit_program(void);

/* sets Task struct's is_checked to true and updates checked_display
 * takes input as a parameter to evaluate which task to update
 */
void check_task(char input[]);

// sets all task_list element's active status to FALSE and clears other Task.member as well
void empty_list(void);

void remove_task(char input[]);

// checks if the task_list has any elements with active status
void is_list_empty(void);

#endif // PROTOTYPES_H
