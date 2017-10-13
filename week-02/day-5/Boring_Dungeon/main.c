#include "guesser.h"

int main()
{
    welcome();
    getch();
    map_crawler();

    return 0;
}

void welcome()
{
    printf("                  ---------------------------------\n"
           "                  ''''WELCOME TO BORING DUNGEON''''\n"
           "                  ---------------------------------\n"
           "                  -----PRESS ANY KEY TO START------\n\n"
           "                           Move with WASD\n");
}

void start_guessing()
{
    system("cls");
    printf(
           "                 W     \n"
           "              -------  \n"
           "                 I   \n"
           "                ZZZ  \n"
           "I am a WIZARD and this is a game where you will have to guess a number between 1 and 100\n\n"
           "Guess it right and i will show you the EXIT of the DUNGEON.\n\n"
           "Otherwise you are DEAD!\n\n");

    game(1, 1, 1, 1);
}

int random_generator(int min, int max)
{
    int result = 0;

    srand(time(NULL));

    do {
        result = rand() % 100;
    } while(result < min || result > max);

    return result;
}

int give_min_limit()
{
    int min = 0;

    printf("What is the lower end of the range you want to guess in?\n");

    do {
        printf("It should be above 0 and below 100: \n");
        scanf("%d", &min);
    } while (min < 1 || min > 99);

    return min;
}

int give_max_limit(int min)
{
    int max = 0;

    printf("What is the higher end of the range you want to guess in?\n");

    do {
        printf("It should be above the min, which is %d and below 101: \n", min);
        scanf("%d", &max);
    } while (max <= min || max > 100);

    return max;
}

int calculate_lives(int min, int max)
{
    int range = 0;
    int lives = 0;
    range = max - min;

    do {
        range = range / 2;
        lives++;
    } while (range > 1);

    return lives;
}

void play(int target, int lives, int min, int max)
{
    int guess = 0;

    printf("Let's begin the game! you have %d tries to guess the number correctly.\n", lives);
    do {
        printf("Enter your guess: \n");
        scanf("%d", &guess);
        --lives;

        if (lives > 0) {
        if (guess > target)
            printf("Your guess was higher than the target nr.\n");
        else if (guess < target)
             printf("Your guess was lower than the target nr.\n");
        }

        if (guess == target) {
            win();
            break;
        } else if ((guess < min || guess > max) && lives > 0) {
            printf("Your guess was out of the original ranges.\n"
                   "Focus your guesses between %d and %d.\n"
                    "Anyway, you have %d lives left.\n", min, max, lives);
        } else if (lives > 0) {
           printf("You have %d lives left. Guess again!\n", lives);
        } else {
            lose(target);
        }

    } while (lives > 0);
}

void win()
{
    printf("%s", map_victory);
    printf("Congratulations, you guessed correctly!!!\n"
           "COME, THE EXIT IS HERE!");
}

void lose(int target)
{
    printf("%s", map_defeat);
    printf("You have 0 lives left\n");
    printf("You failed miserably. Anyway, i thought %d.\n", target);
    printf("You were defeated. You will never leave the dungeon. |R|I|P|.\n\n"
            "Hit a key to finish game.\n");
            getch();
}

void game(int min, int max, int target, int lives)
{
    min = give_min_limit();
    max = give_max_limit(min);
    target = random_generator(min, max);
    lives = calculate_lives(min, max);
    play(target, lives, min, max);
}


void monster_fight()
{
    int hp_player = 2;
    int hp_monster = 2;
    int dmg_monster = 0;
    int dmg_player = 0;

    system("cls");
    printf(
           "                 O     \n"
           "              -------  \n"
           "                 I   \n"
           "                MMM  \n"
           "I am a MONSTER, if your defeat me, you can loot my cave and leave the dungeon.\n"
           "You have %d hp and i have %d hp. Hit any key to start!\n\n", hp_player, hp_monster);

           getch();

    while (1) {

        dmg_monster = random_generator(11, 30) / 3 - 2;
        dmg_player = random_generator(3, 10) - 2;

        if (dmg_monster > dmg_player) {
            --hp_player;
            printf("I made %d damage and you made only %d. Thus you left %d hp.\n", dmg_monster, dmg_player, hp_player);
        } else if (dmg_monster < dmg_player) {
            --hp_monster;
            printf("I made %d damage and you made %d. Thus i have left %d hp.\n", dmg_monster, dmg_player, hp_monster);
        } else {
            printf("I made %d damage and you made %d. Thus attacks were countered.\n", dmg_monster, dmg_player);
        }

        if (hp_monster == 0) {
            printf("%s", map_victory);
            printf("You defeated me. Here is my |3 GOLD| and the |EXIT| behind me : ( \n"
                   "Hit a key to go away.\n");
            getch();
            break;
        }

        if (hp_player== 0) {
            printf("%s", map_defeat);
            printf("You were defeated. You will never leave the dungeon.\n\n"
                   "                       |R|I|P|"
                   "Hit a key to finish game.\n");
            getch();
            break;
        }

        printf("Hit any key to keep on fighting.\n\n");
        getch();

    }

}

void map_crawler ()
{
    int position = 1;

    system("cls");

    char input  = 0;

    printf("%s", map1);

    do {

        input = getch();

        if (input == '1') {
                break;
        } else {
            switch (position) {
                case 1:
                    if (input == 's') {
                    system("cls");
                    printf("%s", map2);
                    position = 2;
                    }
                    break;
                case 2:
                    if (input == 'w') {
                    system("cls");
                    printf("%s", map1);
                    position = 1;
                    } else if (input == 's') {
                    system("cls");
                    printf("%s", map3);
                    position = 3;
                    }
                    break;
                case 3:
                    if (input == 'w') {
                    system("cls");
                    printf("%s", map2);
                    position = 2;
                    } else if (input == 's') {
                    system("cls");
                    printf("%s", map4);
                    position = 4;
                    }
                    break;
                case 4:
                    if (input == 'w') {
                    system("cls");
                    printf("%s", map3);
                    position = 3;
                    } else if (input == 'a') {
                    system("cls");
                    printf("%s", map5g);
                    position = 7;
                    getch();
                    start_guessing();
                    return;
                    } else if (input == 'd') {
                    system("cls");
                    printf("%s", map6m);
                    position = 7;
                    getch();
                    monster_fight();
                    return;
                    }
                    break;
                }
            }

    }   while (1);

    printf("\ngame over");
}



