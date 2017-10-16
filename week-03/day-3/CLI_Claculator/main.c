#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
operation

1. open screen
2. operation prompt to ask for and store user input, and if enter was hit, it calls for input_processor
3. input processor processes text
4. input processor passes parameters to operation_selector
5. operation_selector picks proper operation, and passes parameters to it, and returns with the result
6. result is placed to screen
7. control passed back to operation_promt
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
int addition(int operand1, int operand2);
int substraction(int operand1, int operand2);
double logartihm(int base, int x);
int is_input_valid (char operand1[], char operand2[], char opertr[], char operand_trest[]);



int main()
{



    open_screen();
    atexit(bye);
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

    char input[8];
    int i = 0;
    char c = 0;

    while (c !=  '\n') {
            c = getchar();
            input[i] = c;
            if(input[0] == '\n'){
                operation_prompt();
            }
            i++;
    }

        if (input[0] != '\n')
                input[i - 1] = '\0';

        if (!strcoll(input, "help")) {
            printf("%d\n", strcoll(input, "help"));
            help();
        } else if (!strcoll(input, "clear")) {
            printf("%d\n", strcoll(input, "clear"));
            clear();
        } else if (!strcoll(input, "exit")) {
            printf("%d\n", strcoll(input, "exit"));
            void exit_function();
        } else if (input[0] != '\n') {
            error_message();
        }
//
//    switch (check) {
//        case 435:
//            printf("%d\n", strcoll(input, "help"));
//            help();
//        case 14:
//            printf("%d\n", strcoll(input, "help"));
//            exit_function();
//        case 74:
//            printf("%d\n", strcoll(input, "help"));
//            clear();
//        case 10:
//            printf("%d\n", strcoll(input, "help"));
//            operation_prompt();
//        default:
//            error_message();
//    }


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
    char input[100];

    printf("ready to take instructions\n");
    gets(input);

    printf("operation_prompt took the following as input: ");
    puts(input);
    input_processor(input);
}

void input_processor(char input[])
{
    char operand1[10] = "\0";
    char operand2[10] = "\0";
    char opertr[10] = "\0";
    char operand_tresh[10] = "\0";

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


    printf("operand1 is %s\n", operand1);
    printf("operatr is %s\n", opertr);
    printf("operand2 is %s\n", operand2);
    printf("operand_tresh is %s\n", operand_tresh);


     if (operand_tresh[0] != '\0') {
        printf("there is no place for a 3rd operand\n");
     } else {
        switch(opertr[0]) {
            case '+':
                printf("addition was %d\n", addition(5, 6));
                break;
            case '-':
                printf("substrction was %d\n", substraction(6, 5));
                break;
            case 'l':
                printf("log was %f\n", logartihm(2, 8));
        }
     }

    operation_prompt();
}

void bye(void)
{
    printf("====================================\n"
           "=====SEE YOU, SPACE CALCULATOR======\n"
           "====================================\n");
}

int addition(int operand1, int operand2)
{
    return operand1 + operand2;
}

int substraction(int operand1, int operand2)
{
    return operand1 - operand2;
}
double logartihm(int base, int x)
{

    // should take opertr as 3rd argument and chack with strcmpr or similar for correct matching
  double base_d = (double) base;
  double x_d = (double) x;

  return (log10(x_d) / log10(base_d));
}
