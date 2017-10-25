#include <stdio.h>
#include <stdlib.h>

//TODO: write a C program which can find the intersection point of two section
// RESULTS: http://www.ambrsoft.com/MathCalc/Line/TwoLinesIntersection/TwoLinesIntersection.htm

/* f(x) = ax + c;
 * g(x) = bx + d; a, b = slope
*/

typedef struct
{
    float x;
    float y;

} point_t;

typedef struct
{
    point_t start;
    point_t end;

} section_t;

float intersection_point_x(section_t sec1, section_t sec2)
{
    float a = (sec1.end.y - sec1.start.y) / (sec1.end.x - sec1.start.x);
    float b = (sec2.end.y - sec2.start.y) / (sec2.end.x - sec2.start.x);
    float c = (sec1.start.y - (sec1.start.x * a));
    float d = (sec2.start.y - (sec2.start.x * b));

    float x = (d - c) / (a- b);

    return x;
}

float intersection_point_y(section_t sec1, section_t sec2)
{
    float a = (sec1.end.y - sec1.start.y) / (sec1.end.x - sec1.start.x);
    float b = (sec2.end.y - sec2.start.y) / (sec2.end.x - sec2.start.x);
    float c = (sec1.start.y - (sec1.start.x * a));
    float d = (sec2.start.y - (sec2.start.x * b));

    float y = (a * d - b * c) / (a - b);

    return y;
}

point_t intersection_point(float x, float y)
{
    point_t intersection;

    intersection.x = x;
    intersection.y = y;

    return intersection;
}

int main()
{
    section_t first_sect, second_sect;

    first_sect.start.x = 90;
    first_sect.start.y = 1;
    first_sect.end.x = 2;
    first_sect.end.y = -23;

    second_sect.start.x = -4;
    second_sect.start.y = 9;
    second_sect.end.x = 45;
    second_sect.end.y = 3;

    float x = intersection_point_x(first_sect, second_sect);
    float y = intersection_point_y(first_sect, second_sect);
    point_t intersect = intersection_point(x, y);
    printf("Intersection point: x = %f, y = %f.\n", intersect.x, intersect.y);

    return 0;
}
