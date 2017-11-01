/*
 * Take the previous exercise and add a function which sorts the elements in an ascending order.
 *
 * Test it in the main function and print the results.
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

void bubble_sort(t_number_bank *bank)
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
            bank->p[i] = 0;
            position++;
        }
    }
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
    printf("i am returning number_bank.p[%d]: %d\n", retur_index, new_bank.p[retur_index]);

    retur_index = 2;
    printf("i am returning number_bank.p[%d]: %d\n", retur_index, new_bank.p[retur_index]);

    printf("replacing a number over the index limit (thus incr. array size):\n");
    replace_number_at_index_even_if_array_is_too_small(&new_bank, 999, 20);
    printer(new_bank);

    printf("sorting elements of number array:\n");
    bubble_sort(&new_bank);
    printer(new_bank);

    return 0;
}
