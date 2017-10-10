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

    memset(buffer,0,strlen(buffer));

    int i = 0;
    char c = 0;
    while (getchar() !=  EOF) {


        buffer[i] = getchar();
        i++;
    }


    //TODO:
    // Print it out
    printf("%s", buffer);


    return 0;
}
