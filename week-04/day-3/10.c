#include <stdio.h>
#include <time.h>
#include <conio.h>

struct tm start(time_t raw_tm);
struct tm stop(time_t raw_tm);
void time_diff(struct tm t1, struct tm t2, struct tm *diff);

//TODO: write a stopwatch program. If you hit enter start the stopwatch, if you hit enter again stop the watch. If you hit escape, the program should exit.
//use the time.h header: https://www.tutorialspoint.com/c_standard_library/c_function_localtime.htm
//it's enough if you can measure the elapsed seconds, and minutes

int main()
{
    struct tm start_time, stop_time, diff;
	time_t raw_time;

    char c = 0;
    int flag = 0;

    do {
    c = getch();

    if ( c == '\r' && flag == 0) {
        time(&raw_time);
        start_time = start(raw_time);
        flag = 1;
    } else if ( c == '\r') {
        time(&raw_time);
        stop_time = stop(raw_time);
        flag = 2;
    }

    if (flag == 2) {
        time_diff(start_time, stop_time, &diff);
        printf("stopper was running for %d:%d\n", diff.tm_min, diff.tm_sec);
        flag = 0;
    }

	} while(c != 27);

    return 0;
}

struct tm start(time_t raw_tm) {
    struct tm start_time;
    start_time = *localtime(&raw_tm);
    printf("stopper started\n");
    printf("start time: %2d:%2d\n", start_time.tm_min, start_time.tm_sec);
    return start_time;
}

struct tm stop(time_t raw_tm) {
    struct tm stop_time;
    stop_time = *localtime(&raw_tm);
    printf("stopper stopped\n");
    printf("stop time: %2d:%d\n", stop_time.tm_min, stop_time.tm_sec);
    return stop_time;
}

void time_diff(struct tm t1, struct tm t2, struct tm *diff){
    diff->tm_min = t2.tm_min - t1.tm_min;
    diff->tm_sec = t2.tm_sec - t1.tm_sec;

    if (diff->tm_sec < 0) {
        diff->tm_min-= 1;
        diff->tm_sec+= 60;

    }
}
