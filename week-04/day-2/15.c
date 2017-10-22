#include <stdio.h>
#include <string.h>

void reverse_name(
    char *name, //in
    char *reversed_name); //out

int main(void)
{
	char name[] = "wayne gretzky";

    char reversed[50];

    //write a function which reverse a name's last name and first name. Use a void function. Put your 'return' value in the second parameter.

    reverse_name(name, reversed);

    puts(reversed);

}

void reverse_name(char *name, char *reversed_name)
{
    int space_pos = 0;
    strcpy(reversed_name, name);

    for (int i = 0; i < strlen(name); i++) {
        if (name[i] == ' ') {
            space_pos = i;
            break;
        }
    }

    for (int i = 0; i < strlen(name) - space_pos - 1; i++) {
        reversed_name[i] = name[space_pos + 1 + i];
    }

    reversed_name[strlen(name) - space_pos - 1] = ' ';

    for (int i = 0; i < space_pos; i++) {
        reversed_name[strlen(name) - space_pos + i] = name[i];
    }

    reversed_name[strlen(reversed_name) + 1] = '\0';
}
