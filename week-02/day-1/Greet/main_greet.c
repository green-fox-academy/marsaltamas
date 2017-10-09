#include <stdio.h>
#include <stdlib.h>
#include "greet_funct.h"
#include "variables.h"

// define a variable and assign the value `Greenfox` to it in a .h file
// create a function called `greet` that greets it's input parameter
// define more names to greet, call the function multiple times

int main()
{
    greet(GREENFOX);
    greet(TAMAS);
    greet(EVERYONE);


    return 0;
}


void greet(char *name_to_greet)
{

    printf("Greetings, %s!\n", name_to_greet);

}
