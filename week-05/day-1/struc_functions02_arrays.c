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

// for testing structure with flexible array size/static struct

typedef struct number_bank {
    int quantity_stored;
    int stored_numbers[];
} t_number_bank;

t_number_bank number_banki;

void add_number_at_end(t_number_bank *bank, int to_add);

void printer(t_number_bank *bank)
{
    printf("printing number_bank:\n");
    for (int i = 0; i < bank->quantity_stored; i++) {
        printf("number_bank[%d]: %d\t numbers stored: %d\n", i, bank->stored_numbers[i], bank->quantity_stored);
    }
    printf("------------------------------------------\n");
}

int main()
{


    for (int i = 0; i < 25; i++) {
        add_number_at_end(&number_banki, i);
    }

    printer(&number_banki);

    return 0;
}


void add_number_at_end(t_number_bank *bank, int to_add)
{
    bank->stored_numbers[bank->quantity_stored] = to_add;
    bank->quantity_stored++;
}
