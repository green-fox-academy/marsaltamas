#include <stdio.h>
#include <string.h>


int main() {
    char buffer[255];    // Buffer variable for user input
    char temp[1];

    //TODO:
    // Get the user's name with gets

    printf("Please enter your whole name: ");
    gets(buffer);

    //TODO:
    // Print it out with puts

    puts(buffer);

    //TODO:
    // Get the user's pet name with getch

    printf("Please enter your cat's name letter by letter: ");

    int i = 0;
    char c = 0;

    while (c !=  '\n') {
        c = getchar();
        buffer[i] = c;
        i++;
    }

    buffer[i - 1] = '\0';

    //TODO:
    // Print it out

    printf("%s", buffer);

    return 0;
}
