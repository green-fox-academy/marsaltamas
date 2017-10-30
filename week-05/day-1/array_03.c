/*
 * Create a 2 dimensonal array of characters. 8x8
 * Fill the array with X and space alternating.
 * Print it out row by row. (It should resemble a chess board)
 * Designate a character for each chess peace. (Queen could be Q, King could be K, etc.)
 * Set up the start of a game.
 * Print it out again.
 * Make one move with a horse.
 * Print it again.
 */


#include <stdlib.h>
#include <time.h>
#include <stdio.h>

 void array_printer(char array[][9], int size);

int main()
{
    int size = 9;
    char board[size][size];

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++) {
            if (j == 0 && i > 0)
                board[i][j] = i + 64;
            else if (i == 0 && j > 0)
                board[i][j] = j + 48;
            else if (i % 2 && j % 2)
                board[i][j] = 'x';
            else if (!(i % 2) && !(j %2))
                board[i][j] = 'x';
            else
                board[i][j] = ' ';
            }
    }

    printf("empty board:\n");
    array_printer(board, size);
    printf("\n");


    for (int j = 1; j < size; j++) {
        board[2][j] = 'P';
        board[7][j] = 'P';
    }

    board[1][1] = 'T';
    board[1][8] = 'T';
    board[8][1] = 'T';
    board[8][8] = 'T';
    board[1][2] = 'N';
    board[1][7] = 'N';
    board[8][2] = 'N';
    board[8][7] = 'N';
    board[1][3] = 'B';
    board[1][6] = 'B';
    board[8][3] = 'B';
    board[8][6] = 'B';
    board[1][4] = 'Q';
    board[8][4] = 'Q';
    board[1][5] = 'K';
    board[8][5] = 'K';

    printf("starting board:\n");
    array_printer(board, size);
    printf("\n");

    board[1][2] = ' ';
    board[3][3] = 'N';

    printf("N to C3:\n");
    array_printer(board, size);
    printf("\n");

    return 0;
}

void array_printer(char array[][9], int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c ", array[i][j]);
        }
        printf("\n");
    }
}
