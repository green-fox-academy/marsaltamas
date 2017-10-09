#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int speed_of_sound = 340; //  [m/s]
int give_me_distance(int time);
float give_me_distance_in_km(int time);

//as you can see local variable values can use the same name
//like time and distance and have a different values
//think about the given functions as well, are we using them correctly?

int main()
{
    int time = 32;

    printf("The distance between me and the lightning if the sound reaches me in\n"
           "%d sec is %d meters.\n", time, give_me_distance(time));
    printf("The distance between me and the lightning if the sound reaches me in\n"
           "%d sec is %.2f kilometers.\n", time, give_me_distance_in_km(time));

	return 0;

}

int give_me_distance(int time)
{
    //calculate the distance between you and a lighting, distance is returned in [m]
    //the sound of it reaches you in 5 seconds
    //distance = time * speed_of_sound

    // time is in [s]
    // distance is in [m]

    //as you can see the time and the distance is a local variable, we can only
    //access them in this function (with these values), but the speed_of_sound is a global variable
    //we can use it without any declaration

    return time * speed_of_sound;

}

float give_me_distance_in_km(int time)
{
    //calculate the distance again but this time the result should be in kilometers
    //this time the sound reaches you in 50 seconds

    float divider = 1000;
    // time is in [s]
    float distance; // [m]

    //here we have a third local variable called divider

    return (float) time * speed_of_sound / divider;

}

