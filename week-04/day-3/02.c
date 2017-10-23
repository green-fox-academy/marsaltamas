#include <stdio.h>

typedef struct RectangularCuboid {
    double a;
    double b;
    double c;
} rec_cub_t;

// TODO:
// Write a function called "GetSurface" that takes a RectangularCuboid
// and returns it's surface

double get_surface(rec_cub_t rec_cub);

// TODO:
// Write a function called "GetVolume" that takes a RectangularCuboid
// and returns it's volume

double get_volume(rec_cub_t rec_cub);
double get_volume_p(rec_cub_t *rec_cub);

int main()
{
    rec_cub_t rec_cub = {6, 6, 6};
    rec_cub_t *rec_cub_p = &rec_cub;

    printf("surface : %.2f unit^squared\n", get_surface(rec_cub));
    printf("volume: %.2f unit^cubed\n", get_volume(rec_cub));
    printf("volume with pointer func: %.2f unit^cubed\n", get_volume_p(rec_cub_p));

    return 0;
}

double get_surface(rec_cub_t rec_cub)
{
    double surface = rec_cub.a * rec_cub.b * 2 + rec_cub.a * rec_cub.c * 2 + rec_cub.b * rec_cub.c * 2;
    return surface;
}
double get_volume(rec_cub_t rec_cub)
{
    double volume = rec_cub.a * rec_cub.b * rec_cub.c;
    return volume;
}

double get_volume_p(rec_cub_t *rec_cub_p)
{
    double volume = rec_cub_p->a * rec_cub_p->b * (*rec_cub_p).c;
    return volume;
}
