#include <stdio.h>
#include <string.h>
#include <conio.h>

/**
Discover and understand the working method of this program
find and fix all the bugs
*/

struct task {
	char name[50];
	int done;
	int prio;
};

struct task tasks[100];
int num_tasks = 0;

void print_welcome();
void options();
void see_tasks();
void tasks_prio();
void new_task();
void rm_task();
void complete_task();
void prompt();

int main()
{

    print_welcome();
	options();
	prompt();

	return 0;
}

void print_welcome()
{

	printf("hello, this is a ToDo app, you can organize your tasks here!\n\n"
            "============================================================\n");

}

void options()
{

	printf("CLI Todo application\n");
	printf("====================\n");
	printf("- to see all the tasks press 1\n");
	printf("- to see all the tasks by prio press 2\n");
	printf("- for a new task enter 3\n");
	printf("- to remove task press 4\n");
	printf("- to mark a task complete press 5\n");
	printf("- to list the possible options press 6\n");
	printf("- to clear the screen press 7\n");
	printf("- to close the program please press 0\n");

}

void see_tasks()
{

	printf("Num | Tasks\n");
	for (int i = 0; i < num_tasks; i++) {
		if (tasks[i].done) {
			printf("%d [x] - %s\n", i + 1, tasks[i].name);
		} else {
			printf("%d [ ] - %s\n", i + 1, tasks[i].name);
		}
	}
}

void tasks_prio()
{
    printf("Prio | Tasks\n");

	for (int i = 0; i < num_tasks; i++) {
		for (int j = 5; j > 0; j-- ) {
			if (tasks[i].prio == j) {
				printf("%d - %s\n", tasks[i].prio, tasks[i].name);
			}
		}
	}
}

void new_task()
{
	printf("Enter the name of the task: \n");
	gets(&tasks[num_tasks].name);
	printf("Enter the priority of the task (between 1 and 5): \n");
	scanf("%d", &tasks[num_tasks].prio);
	getchar();
	tasks[num_tasks].done = 0;
	num_tasks++;
}

void rm_task()
{
    int index_task = 0;
    printf("Enter the index of the task\n");
    scanf("%d", &index_task);
   // getchar();

	for (int i = index_task; i < num_tasks; i++) {
		strcpy(tasks[i].name, tasks[i + 1].name);
		tasks[i].prio = tasks[i + 1].prio;
		tasks[i].done = tasks[i + 1].done;
	}
	num_tasks--;
}

void complete_task()
{
    int index_cmp;
    printf("Enter the index of the task\n");
    scanf("%d", &index_cmp);
    getchar();

	tasks[index_cmp - 1].done = 1;

}

void clear_screen()
{
	system("cls");
}

void prompt()
{
    char choice;

	while (1) {


		Sleep(500);
		//clear_screen();
		printf("Please enter what you want to do: ");
		choice = getchar();
		char c = 0;
		while (c != '\n')
			c = getchar();

        switch (choice) {
		 case '0':
			printf("program will end now");
			exit(0);
		case '1':
			see_tasks();
			break;
		case '2':
			tasks_prio();
			break;
		case '3':
			new_task();
			break;
		case '4':
			rm_task();
			break;
		case '5':
			complete_task();
			break;
        case '6':
			options();
			break;
        case '7':
			clear_screen();
			break;
		default:
			printf("Please choose from the given options\n");
		}
	}

}
