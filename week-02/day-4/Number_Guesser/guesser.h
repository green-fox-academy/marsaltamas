#ifndef GUESSER
#define GUESSER

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game(int min, int max, int target, int lives);
void welcome();
int give_min_limit();
int give_max_limit(int min);
int random_generator(int min, int max);
int calculate_lives(int min, int max);
void play(int target, int lives, int min, int max);
void win();
void lose(int target);

#endif // GUESSER


