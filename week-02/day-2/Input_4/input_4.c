#include <stdio.h>
#include <string.h>

void func();
int input_nr = 0;
char input_name[] = "";

int main()
{
    //write a void function which asks for a number with scanf and print it out with printf,
    //then asks for a name with gets, and print it out with puts
    //you will notice something is wrong
    //try to solve the problem

    func();

    return 0;
}

void func()
{
    printf("Please enter a number!\n");
    scanf("%d", &input_nr);
    printf("You entered %d.\n", input_nr);

    fflush(stdin);
    puts("Please enter a name!");
    gets(input_name);
    puts("You entered:");
    puts(input_name);
}
