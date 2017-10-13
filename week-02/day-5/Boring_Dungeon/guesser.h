#ifndef GUESSER
#define GUESSER

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void welcome();
void game(int min, int max, int target, int lives);
void monster_fight();
void start_guessing();
int give_min_limit();
int give_max_limit(int min);
int random_generator(int min, int max);
int calculate_lives(int min, int max);
void play(int target, int lives, int min, int max);
void win();
void lose(int target);

char map1[] =
    "             | x |\n"
    "             |   |\n"
    "             |   |\n";

char map2[] =
    "             |   |\n"
    "             | x |\n"
    "             |   |\n";

char map3[] =
    "             |   |\n"
    "             |   |\n"
    "             | x |\n";

char map4[] =
    "             |   |\n"
    "             |   |\n"
    "             |   |\n"
    "             <_x_>\n";

char map5m[] =
    "             |   |\n"
    "             |   |\n"
    "             |   |\n"
    "           |Mx___|\n";

 char map5g[] =
    "             |   |\n"
    "             |   |\n"
    "             |   |\n"
    "           |Gx___|\n"
    "You are about to play a NUMBER GUESSING game!\n"
    "Press a key to start!\n\n";

char map6m[] =
    "             |   |\n"
    "             |   |\n"
    "             |   |\n"
    "             |___xM|\n"
    "You are about to fight a MONSTER!\n"
    "Press a key to start!\n\n";

 char map6g[] =
    "             |   |\n"
    "             |   |\n"
    "             |   |\n"
    "             |___xG|\n";

char map_victory[] =
    "           XXXXXXXXXXXXXX\n"
    "           |||VICTORY||||\n"
    "           XXXXXXXXXXXXXX\n";

char map_defeat[] =
    "            XXXXXXXXXX\n"
    "            |||FAIL|||\n"
    "            XXXXXXXXXX\n";

#endif // GUESSER



