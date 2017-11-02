/*
 * Create a structure to represent a list of numbers. The structure should know how many number it has stored.
 * Store the numbers in an array.
 * Create functions to:
 *    * Add a new number at the end.
 *    * Get a number at a given index.
 *    * Replace a number at a given index if it exists.
 *
 * If the array is too small, create a new one, copy everything into it, add the new element and delete the old array.
 *
 * Test in the main function whether everything works.
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

// prints a bank struct
void printer(t_number_bank bank)
{
    for (int i = 0; i < bank.in_bank; i++) {
        printf("bank[%d]: %d\n", i, *bank.p);
        bank.p++;
    }

    printf("num in bank: %d\n", bank.in_bank);
    printf("limit: %d\n", bank.limit);
}

//takes a bank and an int, adds the int to the end of the bank's array
void add_number_at_end(t_number_bank *bank, int number)
{
    bank->p = bank->p + bank->in_bank;
    *bank->p = number;
    bank->p = bank->p - bank->in_bank;
    bank->in_bank++;
}

// takes a bank and an int, returns the position of the int
int get_number_at_index(t_number_bank bank, int number)
{
    return bank.p[number];
}

// replaces the taken bank's int array if that is too small
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

// takes a bank, an int as an index to update, and an int to place as the new value
// if the original array is too small, it is going to be increased to accomodate the new int at given index
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

    int retur_index = 5;
    printf("i am returning number_bank.p[%d]: %d\n", retur_index, number_bank.p[retur_index]);

    retur_index = 2;
    printf("i am returning number_bank.p[%d]: %d\n", retur_index, number_bank.p[retur_index]);

    printf("replacing a number over the index limit (thus incr. array size):\n");
    replace_number_at_index_even_if_array_is_too_small(&new_bank, 999, 20);
    printer(new_bank);



    return 0;
}
