#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//project-guessing-game
//Note: the program gets harder, when you set a lower range

int scan_min(void);
int scan_max(void);
int rand_gen(int min, int max);
int lives_calc(int min, int max);
void start_game(int min, int max);
void guess(int to_guess, int lives);


int main()
{
//	int x, y;
//	int count;
//	int guess = 0;

//	int rand_max;
//	int rand_min;

	start_game(scan_min(), scan_max());

//	for (count = 1; count <= x; count++) {
//		printf("\n>");
//		scanf("%d", &guess);
//
//			if (guess == rand_num) {
//				printf("Yeeeeey, you did well! It took you %d tires!", count);
//				break;
//			} else if (guess > rand_num) {
//				printf("Too big, You have %d, lives left\n", x - count);
//			} else {
//				printf("Too low, You have %d, lives left\n", x - count);
//			}
//	}
//
//	if (count = x)
//		printf("You have used all your lives!");

	return 0;
}

int scan_min(void) {

    int rand_min = 0;

    printf("please add the minimum number!\n");
	scanf("%d", &rand_min);

	return rand_min;
}

int scan_max(void) {

    int rand_max = 0;

    printf("please add the maximum number!\n");
	scanf("%d", &rand_max);

	return rand_max;
}

int rand_gen(int min, int max)
{
    srand(time(NULL));
	int rand_num = rand() % (max + 1 - min) + min;

    return rand_num;
}

int lives_calc(int min, int max)
{
    int lives = 0;

    int y = max - min;
    lives = log10(y) / log10(2) + 1;

    return lives;
}

void start_game(int max, int min)
{
    int lives = lives_calc(min, max);
    int to_guess = rand_gen(min, max);
    printf("I have a number between %d and %d. You have %d lives\n", min, max, lives);
    printf("num to guess %d", to_guess);
    //guess(to_guess, lives);
}


