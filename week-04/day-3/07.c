#include <stdio.h>

typedef struct Pirate {
    char name[256];
    int has_wooden_leg;
    short int gold_count;
} Pirate_t;

// TODO:
// Create a function that takes an array of pirates (and it's length) then returns the sum of the golds of all pirates

int gold(Pirate_t pirate_array[], int size);
void printer(Pirate_t pirate_array[], int size);

// TODO:
// Create a function that takes an array of pirates (and it's length) then returns the average of the gold / pirate

double avg_gold(Pirate_t pirate_array[], int size);

// TODO:
// Create a function that takes an array of pirates (and it's length) then returns the name of the
// richest that has wooden leg

char *richest_w_wood(Pirate_t pirat_array[], int size);

int main() {
    struct Pirate pirates[] = {
        {"Jack", 0, 18},
        {"Uwe", 1, 8},
        {"Hook", 1, 12},
        {"Halloween kid", 0, 0},
        {"Sea Wolf", 1, 14},
        {"Morgan", 0, 1}
    };

    printer(pirates, 6);
    printf("The pirates have a total of %d gold.\n", gold(pirates, 6));
    printf("The pirates have %.2f gold on average.\n", avg_gold(pirates, 6));
    printf("The richest with wooden leg is %s", richest_w_wood(pirates, 6));

    return 0;
}

void printer(Pirate_t pirate_array[], int size)
{
    for (int i = 0; i < size; i++) {
        printf("name: %s\n", pirate_array[i].name);
        printf("has wooden leg %d\n", pirate_array[i].has_wooden_leg);
        printf("gold: %d\n", pirate_array[i].gold_count);
    }
}

int gold(Pirate_t pirate_array[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum = sum + pirate_array[i].gold_count;
    }
    return sum;
}

double avg_gold(Pirate_t pirate_array[], int size)
{
    return (float) gold(pirate_array, size) / size;
}

char *richest_w_wood(Pirate_t pirat_array[], int size)
{
    static Pirate_t richest_w_wood = {" ", 0, 0};

    for (int i = 0; i < size; i++) {
        if (pirat_array[i].gold_count > richest_w_wood.gold_count && pirat_array[i].has_wooden_leg)
            richest_w_wood = pirat_array[i];
    }

    return richest_w_wood.name;
}
