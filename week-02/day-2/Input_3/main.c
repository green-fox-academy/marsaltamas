#include <stdio.h>


void char_to_ascii();

int main()
{
    //as you know, a character is represented as a numeric value(ASCII value) in the memory
    //write a function which asks for one charcter and prints out the character in character format then in ASCII too

    char_to_ascii();

    return 0;
}

void char_to_ascii()
{
    char chr;
    puts("Please enter a character to see it in char format and its ASCII value: ");
    chr = getchar();
    printf("char format: %c\n", chr);
    printf("ASCII value: %d\n", chr);

}
