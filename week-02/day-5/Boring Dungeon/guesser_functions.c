#include "guesser.h"

void welcome()
{
    printf("This is a game where you will have to guess a number between 1 and 100\n"
           "you will have a certain amount of lives to guess depending on the range\n"
           "you provide. You can never be sure if you can guess the number.\n");
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

    printf("Please enter the lower end of the range you want to guess in.\n");

    do {
        printf("It should be above 0 and below 100: \n");
        scanf("%d", &min);
    } while (min < 1 || min > 99);

    return min;
}

int give_max_limit(int min)
{
    int max = 0;

    printf("Please enter the higher end of the range you want to guess in.\n");

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
    printf("Congratulations, you guessed correctly!!!");
}

void lose(int target)
{
    int cont = 0;

    printf("You have 0 lives left\n");
    printf("You failed miserably. Anyway, the machine thought %d.\n", target);
    printf("Hit 1 if you want to play again, and hit any other key to quit: \n");
    fflush(stdin);
    scanf("%d", &cont);
    fflush(stdin);

    if (cont == 1) {
        printf("Hope this time you will do better! Good luck!\n");
        game(1, 1, 1, 1);
    } else {
        printf("Thanks for playing! See you next time!\n");
        exit(0);
    }

}

void game(int min, int max, int target, int lives)
{
    min = give_min_limit();
    max = give_max_limit(min);
    target = random_generator(min, max);
    lives = calculate_lives(min, max);
    play(target, lives, min, max);
}



