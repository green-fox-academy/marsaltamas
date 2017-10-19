#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
COORD coord = {0,0};
CONSOLE_SCREEN_BUFFER_INFO SBInfo;


    /* TODO
    - separate to .h files
    - limit int range - nums over 2 bill not working properly + inndicate it in help
     */

/*
OPERATING PROCESS

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
void addition(char operand1[], char operand2[]);
void substraction(char operand1[], char operand2[]);
void multiplication(char operand1[], char operand2[]);
void division(char operand1[], char operand2[]);
void modulo(char operand1[], char operand2[]);
void squaring(char operand1[], char operand2[]);
void square_root(char operand1[], char operand2[]);
void logarithm(char operand1[], char operand2[]);
void bin_to(char operand1[], char operand2[]);
void hex_to(char operand1[], char operand2[]);
void dec_to(char operand1[], char operand2[]);
int is_input_valid (char operand1[], char operand2[], char opertr[], char operand_trest[]);
int is_float(char to_check[]);
int is_correct_target_base(char to_convert[]);
int is_correct_base(int convert_from, char to_convert[]);
int is_valid_operator(char opertr[]);
void set_cursor_pos(int x, int y);
int get_cursor_x();
int get_cursor_y();
float float_converter(char to_convert[]);
void b_to_b_converter(int convert_from, char to_convert[], int convert_to);


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

    set_cursor_pos(0, get_cursor_y()-1);
    printf("%s", "Ready to take instructions:\n");
    operation_prompt();
}

void help(void)
{
    char help_screen[] =
     "               HELP CLI Calculator\n"
    " ================================================\n"
    " usage: [number] [operation] [number]\n"
    " only three space separated operands are accepted\n"
    " numbers can not be longer than 10 characters\n"
    " ================================================\n"
    " Commands:\n"
    "\n"
    " +	summation\n"
    " -	subtraction\n"
    " *	multiplication\n"
    " /	division\n"
    " %	division with remainder\n"
    " ^	squaring\n"
    " <	square root\n"
    " log logarithm\n"
    " ================================================\n"
    " Possible target bases ranging between 2 and 36.\n"
    " binto	binary to hex or dec\n"
    " hexto	hexadecimal to bin or dec\n"
    " decto	decimal to bin or hex\n"
    " ================================================\n"
    " exit	exiting from the program\n"
    " clear	clear the screen\n"
    " help	print usage\n"
    " ================================================\n"
    " Hit enter to continue!\n"
    " ================================================\n";

    printf("%s", help_screen);

    char c = 0;

    do {

        c = getchar();

    } while (c !=  '\n');

    set_cursor_pos(0, get_cursor_y()-1);
    printf("%s", "Ready to take instructions:\n");
    operation_prompt();
}

// clears screen
void clear(void)
{
    system("cls");
    operation_prompt();
}

// exits from program
void exit_function(void)
{
    atexit(bye);
    exit(0);
}

//prints error message to stdout
void error_message(void)
{
    printf("Unknown command, please enter a valid command.\n");

    operation_prompt();
}

//reads user input into buffer, and returns the input string
char  *operation_prompt(void)
{
    char input[50];

    gets(input);

    input_processor(input);
}

/*this function takes input over from operation_promt, processes it
and calls the appropriate functions (math operations, commands, giving back command to operation_prompt */
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

    /*  CHECKING OPERANDS HOW TO PROCEED

    check sequence:
    1. length of input, and length of each input is in between bounds
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
        set_cursor_pos(strlen(input_copy), get_cursor_y() - 1);
        printf("-> Invalid operator. \n");
    } else if (!is_valid_operator(opertr)){
        set_cursor_pos(strlen(input_copy), get_cursor_y() - 1);
        printf("-> Invalid operator. \n");
    }else if (!strcoll(operand1, "help")) {
        help();
    } else if (!strcoll(operand1, "clear")) {
        clear();
    } else if (!strcoll(operand1, "exit")) {
        exit_function();
    } else if (operand_tresh[0] != '\0') {
        set_cursor_pos(strlen(input_copy), get_cursor_y() - 1);
        printf("-> Too many operands had been added.\n");
    } else if (!strcoll(opertr, "+")){
        set_cursor_pos(strlen(input_copy), get_cursor_y() - 1);
        addition(operand1, operand2);
    } else if (!strcoll(opertr, "-")){
        set_cursor_pos(strlen(input_copy), get_cursor_y() - 1);
        substraction(operand1, operand2);
    }  else if (!strcoll(opertr, "*")){
        set_cursor_pos(strlen(input_copy), get_cursor_y() - 1);
        multiplication(operand1, operand2);
    }  else if (!strcoll(opertr, "/")){
        set_cursor_pos(strlen(input_copy), get_cursor_y() - 1);
        division(operand1, operand2);
    }  else if (!strcoll(opertr, "%")){
        set_cursor_pos(strlen(input_copy), get_cursor_y() - 1);
        modulo(operand1, operand2);
    }  else if (!strcoll(opertr, "^")){
        set_cursor_pos(strlen(input_copy), get_cursor_y() - 1);
        squaring(operand1, operand2);
    }  else if (!strcoll(opertr, "<")){
        set_cursor_pos(strlen(input_copy), get_cursor_y() - 1);
        square_root(operand1, operand2);
    }  else if (!strcoll(opertr, "log")){
        set_cursor_pos(strlen(input_copy), get_cursor_y() - 1);
        logarithm(operand1, operand2);
    } else if (!strcoll(opertr, "binto")){
        set_cursor_pos(strlen(input_copy), get_cursor_y() - 1);
        bin_to(operand1, operand2);
    } else if (!strcoll(opertr, "hexto")){
        set_cursor_pos(strlen(input_copy), get_cursor_y() - 1);
        hex_to(operand1, operand2);
    } else if (!strcoll(opertr, "decto")){
        set_cursor_pos(strlen(input_copy), get_cursor_y() - 1);
        dec_to(operand1, operand2);
    }else {
        set_cursor_pos(strlen(input_copy), get_cursor_y() - 1);
        printf("-> Invalid input. \n");
    }

    operation_prompt();
}

// message printed to stdout when exiting program
void bye(void)
{
    printf("====================================\n"
           "=====SEE YOU, SPACE CALCULATOR======\n"
           "====================================\n");
}

// CONVERTERS

//converts string to float
float float_converter(char to_convert[])
{
    float number;
    char *end_p;
    number = strtof(to_convert, &end_p);

    return number;
}

//taking a string as a long int, and converts it from a given base to another base, and prints it out as a string
void b_to_b_converter(int convert_from, char to_convert[], int convert_to)
{
    char to_return[50];
    long int lint_value = 0;

    lint_value = strtol(to_convert, NULL, convert_from);

    itoa(lint_value, to_return, convert_to);

    printf(" = %s\n", to_return);
}


// FORMAT CHECKERS

/* checks if string is containing numbers in correct format, or not
return 1 if format is ok, 0 if format is not float. */
int is_float(char to_check[])
{
    char *end_p;
    strtof(to_check, &end_p);

    if (*end_p != 0) {
        return 0;
    } else {
        return 1;
    }
}

/* returns 1 if the given string can be converted from the given base to int
 returns 0 if it can't be converted or out of the range of 2 or 36 in int form
 convert_from must be between 2 and 36 as an int due to strtol parameter rules*/
int is_correct_base(int convert_from, char to_convert[])
{
    char *end_p;
    strtol(to_convert, &end_p, convert_from);

    if (*end_p != 0)
        return 0;
    else
        return 1;
}

/* returns 1 if the given string contains a valid range and format for target base
 returns 0 if it can't be converted or out of the range of 2 or 36 in int form
 convert_to must be between 2 and 36 as an int due to strtol parameter rules*/
int is_correct_target_base(char to_convert[])
{
    long int target_base = 0;
    char *end_p;
    target_base = strtol(to_convert, &end_p, 10);

    if (*end_p != 0 || target_base > 36 || target_base < 2)
        return 0;
    else
        return 1;
}

//takes the operator as a string, return 1 if it is valid, otherwise return 0.
int is_valid_operator(char opertr[])
{

    char operators[11][6] = {"+", "-", "*", "/", "%", "^", "<", "log", "binto", "hexto", "decto"};
    int flag = 0;

    for (int i = 0; i < 11; i++) {
        if (!(strcmp(operators[i], opertr)))
            flag++;
    }

    if (flag == 1)
        return 1;
    else
        return 0;
}

/*MATH OPERATIONS
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
printing result on screen
returning with result to the proper location on the screen with calling placement function
*/

void addition(char operand1[], char operand2[])
{
    float op1 = float_converter(operand1);
    float op2 = float_converter(operand2);

    int op1_test = is_float(operand1);
    int op2_test = is_float(operand2);

    if ((!op1_test) && (!op2_test)) {
        printf(" = Operand1 and Operand2 are not numbers.\n");
    } else if (!op1_test) {
        printf(" = Operand1 is not a number.\n");
    } else if (!op2_test) {
        printf(" = Operand2 is not a number.\n");
    } else {
        printf(" = %f\n", op1 + op2);
    }
}

void substraction(char operand1[], char operand2[])
{

    float op1 = float_converter(operand1);
    float op2 = float_converter(operand2);

    int op1_test = is_float(operand1);
    int op2_test = is_float(operand2);

    if ((!op1_test) && (!op2_test)) {
        printf(" = Operand1 and Operand2 are not numbers.\n");
    } else if (!op1_test) {
        printf(" = Operand1 is not a number.\n");
    } else if (!op2_test) {
        printf(" = Operand2 is not a number.\n");
    } else {
        printf(" = %f\n", op1 - op2);
    }
}


void multiplication(char operand1[], char operand2[])
{
    float op1 = float_converter(operand1);
    float op2 = float_converter(operand2);

    int op1_test = is_float(operand1);
    int op2_test = is_float(operand2);

    if ((!op1_test) && (!op2_test)) {
        printf(" = Operand1 and Operand2 are not numbers.\n");
    } else if (!op1_test) {
        printf(" = Operand1 is not a number.\n");
    } else if (!op2_test) {
        printf(" = Operand2 is not a number.\n");
    } else {
        printf(" = %f\n", op1 * op2);
    }
}

void division(char operand1[], char operand2[])
{
    float op1 = float_converter(operand1);
    float op2 = float_converter(operand2);

    int op1_test = is_float(operand1);
    int op2_test = is_float(operand2);

    if ((!op1_test) && (!op2_test)) {
        printf(" = Operand1 and Operand2 are not numbers.\n");
    } else if (!op1_test) {
        printf(" = Operand1 is not a number.\n");
    } else if (!op2_test) {
        printf(" = Operand2 is not a number.\n");
    } else if (!op2) {
        printf(" = Division by 0 is not allowed.\n");
    } else {
        printf(" = %f\n", op1 / op2);
    }
}

void modulo(char operand1[], char operand2[])
{
    float op1 = float_converter(operand1);
    float op2 = float_converter(operand2);

    int op1_test = is_float(operand1);
    int op2_test = is_float(operand2);

    if ((!op1_test) && (!op2_test)) {
        printf(" = Operand1 and Operand2 are not numbers.\n");
    } else if (!op1_test) {
        printf(" = Operand1 is not a number.\n");
    } else if (!op2_test) {
        printf(" = Operand2 is not a number.\n");
    } else if (!op2) {
        printf(" = Modulo by 0 is undefined.\n");
    } else {
        printf(" = %f\n", fmod(op1, op2));
    }
}

void squaring(char operand1[], char operand2[])
{
    float op1 = float_converter(operand1);
    float op2 = float_converter(operand2);

    int op1_test = is_float(operand1);
    int op2_test = is_float(operand2);

    if ((!op1_test) && (!op2_test)) {
        printf(" = Operand1 and Operand2 are not numbers.\n");
    } else if (!op1_test) {
        printf(" = Operand1 is not a number.\n");
    } else if (!op2_test) {
        printf(" = Operand2 is not a number.\n");
    } else if (!op1 && !op2) {
        printf(" = The 0th power of 0 is ambiguous.\n");
    } else {
        printf(" = %f\n", pow(op1, op2));
    }
}

void square_root(char operand1[], char operand2[])
{
    float op1 = float_converter(operand1);
    float op2 = float_converter(operand2);

    int op1_test = is_float(operand1);
    int op2_test = is_float(operand2);

    if ((!op1_test) && (!op2_test)) {
        printf(" = Operand1 and Operand2 are not numbers. Operand1 must be 2. Operand 2 must be 0 or greater.\n");
    } else if (!op1_test) {
        printf(" = Operand1 is not a number. Operand 1 must be 2.\n");
    } else if (!op2_test) {
        printf(" = Operand2 is not a number. Operand 2 must be 0 or greater.\n");
    } else if (op1 != 2) {
        printf(" = Operand 1 must be 2. I can calculate only the square root of Operand 2.\n");
    } else if (op2 < 0) {
        printf(" = Operand 2 must be 0 or greater.\n");
    } else {
        printf(" = %f\n", sqrt(op2));
    }
}

void logarithm(char operand1[], char operand2[])
{
    float op1 = float_converter(operand1);
    float op2 = float_converter(operand2);

    int op1_test = is_float(operand1);
    int op2_test = is_float(operand2);

    if ((!op1_test) && (!op2_test)) {
        printf(" = Operand1 and Operand2 are not numbers. Operand1 must be a positive real number not not equals 1. Operand 2 must be above 0.\n");
    } else if (!op1_test) {
        printf(" = Operand1 is not a number. Operand1 must be a positive real number not not equals 1.\n");
    } else if (!op2_test) {
        printf(" = Operand2 is not a number. Operand 2 must be above 0.\n");
    } else if (op1 <= 0 || op1 ==1) {
        printf(" = Operand1 must be a positive real number not not equals 1.\n");
    } else if (op2 <= 0) {
        printf(" = Operand 2 must be above 0.\n");
    } else {
        printf(" = %f\n", log10(op2) / log10(op1));
    }
}

void bin_to(char operand1[], char operand2[])
{
    int op2 = strtol(operand2, NULL, 10); // operand2's int value

    int op1_test = is_correct_base(2, operand1);
    int op2_test = is_correct_target_base(operand2);

    if ((!op1_test) && (!op2_test)) {
        printf(" = Operand1 and Operand2 are invalid.\nOperand1 must be a binary number.\n"
               "Operand 2 must be and integer in the range of 2 and 36.\n");
    } else if (!op1_test) {
        printf(" = Operand1 is invalid. It must a binary number.\n");
    } else if (!op2_test) {
        printf(" = Operand2 is invalid.\nIt must be must be and integer in the range of 2 and 36.\n");
    } else {
         b_to_b_converter(2, operand1, op2);
    }
}

void hex_to(char operand1[], char operand2[])
{
    int op2 = strtol(operand2, NULL, 10); // operand2's int value

    int op1_test = is_correct_base(16, operand1); // is operand1 in hex format?
    int op2_test = is_correct_target_base(operand2);

    if ((!op1_test) && (!op2_test)) {
        printf(" = Operand1 and Operand2 are invalid.\nOperand1 must be a hexadecimal number.\n"
               "Operand 2 must be and integer in the range of 2 and 36.\n");
    } else if (!op1_test) {
        printf(" = Operand1 is invalid. It must a hexadecimal number.\n");
    } else if (!op2_test) {
        printf(" = Operand2 is invalid.\nIt must be must be and integer in the range of 2 and 36.\n");
    } else {
         b_to_b_converter(16, operand1, op2);
    }
}

void dec_to(char operand1[], char operand2[])
{
    int op2 = strtol(operand2, NULL, 10); // operand2's int value

    int op1_test = is_correct_base(10, operand1); // is operand1 in hex format?
    int op2_test = is_correct_target_base(operand2);

    if ((!op1_test) && (!op2_test)) {
        printf(" = Operand1 and Operand2 are invalid.\nOperand1 must be a decimal number.\n"
               "Operand 2 must be and integer in the range of 2 and 36.\n");
    } else if (!op1_test) {
        printf(" = Operand1 is invalid. It must a decimal number.\n");
    } else if (!op2_test) {
        printf(" = Operand2 is invalid.\nIt must be must be and integer in the range of 2 and 36.\n");
    } else {
         b_to_b_converter(10, operand1, op2);
    }
}

// FUNCTIONS TO GET AND SET CURSOR POSITION

void set_cursor_pos(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int get_cursor_x() {

    int x = 0;

    if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &SBInfo)) {
        x = SBInfo.dwCursorPosition.X;
    }

    return x;
}

int get_cursor_y() {

    int y = 0;
    if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &SBInfo)) {
        y = SBInfo.dwCursorPosition.Y;
    }

    return y;
}
