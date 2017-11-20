#include <iostream>
#include <ctime>
#include <windows.h>df

using namespace std;

// Create a simple program which has a time lock
// The program shoul ask for a user input, but the user only has
// 10 seconds to reply, if the user fails (reaches the time limit)
// the program should print out: "failed, it took you too much time"
// This program cloud be the engine of a quiz game.
//

int main()
{
    int answer = 0;
    bool out_timed = false;

    cout << "How much is 2 + 2?" << endl;

    time_t start_time = time(0);

    cin >> answer;

    time_t finish_time = time(0);

    if (finish_time - start_time > 5) {
        out_timed = true;
    }

    if (answer != 4)
        cout << "Incorrect answer.\n";
    else
        cout << "Correct answer.\n";

    if (out_timed)
        cout << "Answer was out of time.";

    return 0;
}
