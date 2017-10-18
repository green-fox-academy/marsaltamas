#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
OPERATIN PROCESS

1. open screen
2. operation prompt to ask for and store user input, and if enter was hit, it calls for input_processor
3. input processor processes text
4. input processor evaluates input to call the proper function to keep on the operation flow
5. called function  receiving parameters to process and to return with the result at expected screen location
6. control passed back to operation_promt

*/

void open_screen (void);
void help(void);
void clear(void);
void exit_function(void);
void error_message(void);
void read_input(void);
char *operation_prompt(void);
void input_processor(char input[]);
void bye(void);
float addition(char operand1[], char operand2[]);
float substraction(char operand1[], char operand2[]);
double logartihm(char operand1[], char operand2[]);
int is_input_valid (char operand1[], char operand2[], char opertr[], char operand_trest[]);

int main()
{
    open_screen();
    return 0;
}

void open_screen (void)
{
    char open_screen[] =
    "          CLI Calculator\n"
    " ====================================\n"
    " usage: [number] [operation] [number]\n"
    " Commands:\n"
    "\n"
    " +	summation\n"
    " -	subtraction\n"
    " *	multiplication\n"
    " /	division\n"
    " %	division with remainder\n"
    " ^	squaring\n"
    " <	square root\n"
    " log	logarithm\n"
    " binto	binary to hex or dec\n"
    " hexto	hexadecimal to bin or dec\n"
    " decto	decimal to bin or hex\n"
    " ====================================\n"
    " exit	exiting from the program\n"
    " clear	clear the screen\n"
    " help	print usage\n"
    " ====================================\n"
    " Hit enter to start!\n"
    " ====================================\n";

    printf("%s", open_screen);

    char c = 0;

    do {

        c = getchar();

    } while (c !=  '\n');

    operation_prompt();
}

void help(void)
{
    printf("there is the help\n");
    operation_prompt();
}

void clear(void)
{
    system("cls");
    operation_prompt();
}

void exit_function(void)
{
    printf("exit was called\n"); // dev message
    atexit(bye);
    exit(0);
}

void error_message(void)
{
    printf("Unknown command, please enter a valid command.\n");

    operation_prompt();
}

//reads user input into buffer, and returns the input string
char  *operation_prompt(void)
{
    char input[50];

    printf("ready to take instructions\n");
    gets(input);

    printf("operation_prompt took the following as input: ");
    puts(input);
    input_processor(input);
}

// this function takes input over from operation_promt, processes it
//and calls the appropriate functions (math operations, commands, giving back command to operation_prompt
void input_processor(char input[])
{
    // tokenizes input line, and breaks down to 4 parts to know which operation to take
    // operand 1, operand2, operator, and operand_tresh - if tresh is not empty, the input is considered invalid
    char operand1[11] = "\0";
    char operand2[6] = "\0";
    char opertr[11] = "\0";
    char operand_tresh[2] = "\0";
    char input_copy[40];
    strcpy(input_copy, input);
    char *reader;

    reader = strtok(input, " ");

    while (reader != NULL) {

        if (operand1[0] == '\0') {
            strcpy(operand1, reader);
        } else if (opertr[0] == '\0') {
            strcpy(opertr, reader);
        } else if (operand2[0] == '\0') {
            strcpy(operand2, reader);
        } else {
            strcpy(operand_tresh, reader);
        }

        reader = strtok(NULL, " ");
    }

    // development messages
    printf("operand1 is %s\n", operand1);
    printf("operatr is %s\n", opertr);
    printf("operand2 is %s\n", operand2);
    printf("operand_tresh is %s\n", operand_tresh);

    // checking operands how to proceed

    /* check sequence:
    1. length of input, and length of eachc input is in between bouds
    2. if operand1 is command
    3. if op4 is empty
    4. operatr check to know which match func to call - > further specific error handling in math op. functions
    5. else: unknown command
    */

    if (strlen(input_copy) > 30){
        printf("The instructions took up to many characters.\n"
               "Please enter an instruction shorter than 30 characters.\n");
    } else if (strlen(operand1) > 10){
        printf("Operand1 took up to many characters.\n"
               "Please enter a number up to 10 characters.\n");
    } else if (strlen(operand2) > 10){
        printf("Operand2 took up to many characters.\n"
               "Please enter a number up to 10 characters.\n");
    } else if (strlen(opertr) > 5){
        printf("Invalid operator. \n");
    } else if (!strcoll(operand1, "help")) {
        help();
    } else if (!strcoll(operand1, "clear")) {
        clear();
    } else if (!strcoll(operand1, "exit")) {
        exit_function();
    } else if (operand_tresh[0] != '\0') {
        printf("Too many operands had been added.\n");
    } else if (!strcoll(opertr, "+")){
        printf("addition was %f \n", addition(operand1, operand2));
    } else if (!strcoll(opertr, "-")){
        printf("substraction was %f \n", substraction(operand1, operand2));
    } else if (!strcoll(opertr, "log")){
        printf("log was %f \n", logartihm(operand1, operand2));
    }

    operation_prompt();
}

void bye(void)
{
    printf("====================================\n"
           "=====SEE YOU, SPACE CALCULATOR======\n"
           "====================================\n");
}

// CONVERTERS

float float_converter(char to_convert[])
{
    return atof(to_convert);
}


/*
MATH OPERATIONS
---------------
---------------
Basics (mandatory) tasks

+
-
*
/
%
squaring
square root
logarithm
binary to
hexadecimal to
decimal to

Advanced tasks
nth roots.

WORK ORDER
----------
taking strings
validating strings
    VALIDTION SEQUENCE
        -isnumber
        -isnumber ok with given operation
converting to numbers
executing operations
converting numbers back to string if necessary
returning with result to the proper location on the screen with calling placement function
*/


float addition(char operand1[], char operand2[]) {
    //return operand1 + operand2;
    printf("addition was called \n");

    float op1 = float_converter(operand1);
    float op2 = float_converter(operand2);

    return op1 + op2;
}

float substraction(char operand1[], char operand2[])
{
    //return operand1 - operand2;
    printf("substraction was called \n");

    float op1 = float_converter(operand1);
    float op2 = float_converter(operand2);

    return op1 - op2;
}

double logartihm(char operand1[], char operand2[])
{

//  should take opertr as 3rd argument and chack with strcmpr or similar for correct matching
//  double base_d = (double) operand1;
//  double x_d = (double) operand2;
//
//  return (log10(x_d) / log10(base_d));
    printf("log was called \n");
    return 0;
}

