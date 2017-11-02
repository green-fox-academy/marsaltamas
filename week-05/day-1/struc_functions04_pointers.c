/*
 * Extend the previous exercise by adding a function that sorts the numbers in a descending order. This function should take
 * the Structure as the first argument as well.
 *
 * Create an enum whit two values: SORT_ASC, SORT_DESC.
 * Create a functions which takes the structure as the first argument and takes the enum as the second and sorts the
 * elements in the structure accordingly, using the other two functions.
 *
 * Test them in the main function. Demonstrate they work.
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#define LIMIT 15

typedef struct number_bank {
    int *p;
    int in_bank;
    int limit;
} t_number_bank;

enum asc_or_desc {SORT_ASC, SORT_DESC};

void printer(t_number_bank bank)
{
    for (int i = 0; i < bank.in_bank; i++) {
        printf("bank[%d]: %d\n", i, *bank.p);
        bank.p++;
    }
    printf("num in bank: %d\n", bank.in_bank);
    printf("limit: %d\n", bank.limit);
}

void add_number_at_end(t_number_bank *bank, int number)
{
    bank->p = bank->p + bank->in_bank;
    *bank->p = number;
    bank->p = bank->p - bank->in_bank;
    bank->in_bank++;
}

int get_number_at_index(t_number_bank bank, int number)
{
    return bank.p[number];
}

void replace_small_array(t_number_bank *bank, int new_array_size, int old_size)
{
    int *new_arr = (int*)malloc(new_array_size*sizeof(int));
    if (!new_arr) {
        perror("Error allocating memory");
        exit(0);
    }
    memset(new_arr, 0, sizeof(int)*new_array_size);

    for (int i = 0; i < old_size; i++) {
        new_arr[i] = bank->p[i];
    }

    free(bank->p);

    bank->p = new_arr;

    bank->in_bank = new_array_size;
}

void replace_number_at_index_even_if_array_is_too_small(t_number_bank *bank, int number, int index)
{
    if (bank->in_bank > index) {
        bank->p[index] = number;
    }
    else {
        replace_small_array(bank, index + 1, bank->in_bank);
        bank->p[index] = number;
    }
    bank->limit = index + 1; // -> actually, there is no limit
}
// takes a bank, sorts its array in ascending order
void bubble_sort_asc(t_number_bank *bank)
{
    int temp = 0;

    for (int i = 0; i < bank->in_bank; i++) {
        for (int j = 0; j < bank->in_bank - i - 1; j++) {
            if (bank->p[j] > bank->p[j + 1]) {
                temp = bank->p[j];
                bank->p[j] = bank->p[j + 1];
                bank->p[j + 1] = temp;
            }
        }
    }
    int position = 0;

    for (int i = 0; i < bank->in_bank; i++) {
        if ( bank->p[i] != 0) {
            bank->p[position] = bank->p[i];
            //bank->p[i] = 0;
            position++;
        }
    }
}
// takes a bank, sorts its array in descending order
void bubble_sort_desc(t_number_bank *bank)
{
    int temp = 0;

    for (int i = 0; i < bank->in_bank; i++) {
        for (int j = 0; j < bank->in_bank - i - 1; j++) {
            if (bank->p[j] < bank->p[j + 1]) {
                temp = bank->p[j];
                bank->p[j] = bank->p[j + 1];
                bank->p[j + 1] = temp;
            }
        }
    }
}
// takes a bank, sorts its array in ascending or descending order
// order == 1: ASCending order; order == 2: DESCending order
void sort_in_requested_order(t_number_bank *bank, int order)
{
    if (order == SORT_ASC)
        bubble_sort_asc(bank);
    else if (order == SORT_DESC)
        bubble_sort_desc(bank);
    else
        printf("Invalid argument.\n");
}

int main()
{
    int int_array[LIMIT]; // booth banks using this array as same pointer assigned to them, which is pointing to this array
    int *p;
    p = int_array;
    srand(time(0));

    for (int i = 0; i < 5; i++) {
        int_array[i] = rand() % 100;
    }

    t_number_bank number_bank;
    number_bank.p = p;
    number_bank.in_bank = 5;
    number_bank.limit = LIMIT;

    printf("printing number bank after init:\n");
    printer(number_bank);

    t_number_bank new_bank = {p, 5, LIMIT};

    printf("printing new bank after init:\n");
    printer(new_bank);

    printf("adding a number at the end of new bank:\n");
    add_number_at_end(&new_bank, 777);
    printer(new_bank);

    printf("sorting in asc order:\n");
    sort_in_requested_order(&number_bank, SORT_ASC);
    printer(number_bank);

    printf("sorting in desc order:\n");
    sort_in_requested_order(&number_bank, SORT_DESC);
    printer(number_bank);

    printf("sorting in invalid request order:\n");
    sort_in_requested_order(&number_bank, 34);

    return 0;
}
