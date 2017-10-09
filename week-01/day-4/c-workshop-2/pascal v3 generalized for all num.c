# include  <stdlib.h>

/* works for every + number */

int main ()
{
    int rows = 10;

    if (rows % 2 == 1)
        rows += 2;

    int spaces_counter = rows / 2 - 1;
    int stars_counter = 1;

    for (int i = 1; i <= rows; i++) {

        if ((i == rows / 2 + 1) && (rows % 2 == 1)) {
        stars_counter-= 2;
        spaces_counter++;
        }

        for (int j = 0; j < spaces_counter; j++) {
            printf("  ");
        }

        if (i < rows / 2)
            spaces_counter--;
        else if (i > rows / 2)
            spaces_counter++;
        else
            printf("");

        for (int k = 0; k < stars_counter; k++) {
            printf("* ");
        }

        if (i < rows / 2)
            stars_counter+=2;
        else if (i > rows / 2)
            stars_counter-=2;
        else
            printf("");

            printf("\n");
    }

    return 0;
}
