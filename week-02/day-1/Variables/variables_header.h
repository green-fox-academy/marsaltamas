#ifndef VARIABLE_HEADER
#define VARIABLE_HEADER

int input;
int op_done = 0;
void get_input ();
int add_10 (int num1);
int add_15(int num1);
int add_22(int num1);
int sub_22 (int num1);
int sub_34 (int num1);

void get_input()
{
    printf("Please enter an integer: ");
    scanf("%d", &input);
    printf("You entered: %d.\n", input);
}

int add_10 (int num1){

    op_done++;
    return num1 + 10;
}

int add_15 (int num1)
{
    op_done++;
    return num1 + 15;
}

int add_22 (int num1)
{
    op_done++;
    return num1 + 22;
}

int sub_22 (int num1)
{
    op_done++;
    return num1 - 22;
}

int sub_34 (int num1)
{
    op_done++;
    return num1 - 22;
}


#endif

