#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} point_t;


// TODO:
// Create a function that constructs a point
// It should take it's x and y coordinate as parameter

point_t create_point(int x, int y);
void point_printer(point_t point);

// TODO:
// Create a function that takes 2 Points as a pointer and returns the distance between them

double distance(point_t *a, point_t *b);

int main()
{
    point_t a = create_point(2, -2);
    point_t b = create_point(10, 1);

    point_printer(a);
    point_printer(b);

    printf("distance between a and b is %f", distance(&a, &b));

    return 0;
}

point_t create_point(int x, int y)
{
    point_t point = {x, y};

    return point;
}

void point_printer(point_t point)
{
    printf("x: %d\n", point.x);
    printf("y: %d\n", point.y);
}

double distance(point_t *a, point_t *b)
{
    double distance;

    distance = sqrt(pow(a -> x - b -> x, 2) + pow(a -> y - b -> y, 2));

    return distance;
}
