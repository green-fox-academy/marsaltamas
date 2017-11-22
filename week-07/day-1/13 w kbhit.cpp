#include <cstddef>
#include <ctime>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

// Create a simple program which has a time lock
// The program shoul ask for a user input, but the user only has
// 10 seconds to reply, if the user fails (reaches the time limit)
// the program should print out: "failed, it took you too much time"
// This program cloud be the engine of a quiz game.
//
// found the solution here (which is not using multiple threads):
// https://stackoverflow.com/questions/421860/capture-characters-from-standard-input-without-waiting-for-enter-to-be-pressed
// https://www.computerhope.com/forum/index.php?topic=104972.0


/*
 * this function takes a char array, a size for that array, and an int as time limit.
 * returns true if time is over or the buffer is full or enter key hit was read from stream.
 * returns false if timer is not over && the buffer is empty.
 */
bool get_input_in_due_time(char *buffer, size_t size, int timeout)
{
    time_t start = time (0);
    size_t n = 0; // set current buffer position

    for ( ; ; ) {
        if (difftime(time(0), start) >= timeout)
            return false; // returning false if timed out and no keys were read from stream

        /*
         * kbhit returns not 0 if a key was found in the stream.
         * so this if block is skipped if stream is empty, otherwise stores the char found to the buffer
         */

        if (kbhit()) {
            if ( n == size - 1 )
            break;

            char ch = (int) getche();

            if (ch == '\r') {
                break;
            } else {
                buffer[n++] = ch;
            }
        }
    }

    buffer[n] = '\0';

    return true;
}

int main()
{
    char buffer[512] = "";
    int guess = 3; // setting target number

    cout << "Please guess the number i was thinking off!\nSubmit your answer with pressing enters: ";

    if (!get_input_in_due_time(buffer, 512, 3)) {
        cout << "\nSorry, time is over!";
        strcpy(buffer, "There was no answer submitted.");
    }

    cout << "\nYour guess was: "  << buffer << endl;

    if (atoi(buffer) == guess)
        cout << "Correct guess!" << endl;
    else
        cout << "Have better luck next time! The number was 3, anyway." << endl;

    return 0;
}


