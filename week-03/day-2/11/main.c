#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void prompt();
void reg(int *registered);
void log_in(int *logged_in, int *registered);
void log_out(int *logged_in);

int main()
{
    prompt();

    //TODO: write a register-login-logout program
    //if you type in register print out "Registration..." or "You are already registered." if you are registered.
	//you are able to log in, if you are already registered, otherwise not. In that case print out "You are not registered.".
    //if you type in login print out "Logging in..." or "Already logged in." if are logged in.
    //if you type in logout print out "Logging out..." or "Already logged out." if are logged out.

    return 0;
}

void prompt()
{
    char command[256];
    int logged_in = 0;
    int registered = 0;

    while (1) {
        printf("Please enter your command: ");
        gets(command);

        if (!strcmp(command, "register")) {
            reg(&registered);
        } else if (!strcmp(command, "login")) {
            log_in(&logged_in, &registered);
        } else if (!strcmp(command, "logout")) {
            log_out(&logged_in);
        } else {
            printf("Unknown command.\n");
        }
    }
}

void reg(int *registered)
{
    if (*registered) {
        printf("Your are already registered.\n");
    }
    else {
        printf("Welcome, now you are registered.\n");
        *registered = 1;
    }

}

void log_in(int *logged_in, int *registered)
{
    if (!*logged_in && *registered) {
        printf("Your are now logged in.\n");
        *logged_in = 1;
    } else if (!*registered){
        printf("You can!t log in, you are not registered.\n");
    } else {
        printf("You are already logged in.\n");
    }
}

void log_out(int *logged_in)
{
     if (*logged_in == 1) {
        printf("You are now logged out.\n");
        exit(0);
    } else {
        printf("You can't logout, as you are not logged in.\n");
    }
}

