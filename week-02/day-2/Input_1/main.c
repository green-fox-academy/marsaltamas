#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char buffer[255], temp[20];   // Buffer variable for user input

    //TODO:
    // Get the user's name with scanf

    printf("Please enter your first name: \n");
    scanf("%s", buffer);

    fflush(stdin);

    printf("Please enter your second name: \n");
    scanf("%s", temp);
    strcat(buffer, " ");
    strcat(buffer, temp);

    //TODO:
    // Print it out with printf

    printf("Your name is: %s", buffer);

    return 0;
}
