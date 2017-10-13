#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main()
{
    int position = 1;


    char map1[] =
        "  | x |\n"
        "  |   |\n"
        "  |   |\n";

    char map2[] =
        "  |   |\n"
        "  | x |\n"
        "  |   |\n";

    char map3[] =
        "  |   |\n"
        "  |   |\n"
        "  | x |\n";

    char map4[] =
        "  |   |\n"
        "  |   |\n"
        "  |   |\n"
        "  <_x_>\n";

    char map5m[] =
        "  |   |\n"
        "  |   |\n"
        "  |   |\n"
        "|Mx___|\n";

     char map5g[] =
        "  |   |\n"
        "  |   |\n"
        "  |   |\n"
        "|Gx___|\n";

        char map6m[] =
        "  |   |\n"
        "  |   |\n"
        "  |   |\n"
        "  |___xM|\n";

         char map6g[] =
        "  |   |\n"
        "  |   |\n"
        "  |   |\n"
        "  |___xG|\n";

        char map7[] =
        "XXXXXXXXXXXXXX"
        "|||VICTORY||||"
        "XXXXXXXXXXXXXX";

        char map8[] =
        " XXXXXXXXXX"
        " |||FAIL|||"
        " XXXXXXXXXX";


        char input  = 0;

        printf("%s", map1);

        do {

            input = getch();

            if (input == '1') {
                    break;
            } else {
                switch (position) {
                    case 1:
                        if (input == 's') {
                        system("cls");
                        printf("%s", map2);
                        position = 2;
                        }
                        break;
                    case 2:
                        if (input == 'w') {
                        system("cls");
                        printf("%s", map1);
                        position = 1;
                        } else if (input == 's') {
                        system("cls");
                        printf("%s", map3);
                        position = 3;
                        }
                        break;
                    case 3:
                        if (input == 'w') {
                        system("cls");
                        printf("%s", map2);
                        position = 2;
                        } else if (input == 's') {
                        system("cls");
                        printf("%s", map4);
                        position = 4;
                        }
                        break;
                    case 4:
                        if (input == 'w') {
                        system("cls");
                        printf("%s", map3);
                        position = 7;
                        } else if (input == 'a') {
                        system("cls");
                        printf("%s", map5g);
                        position = 7;
                        } else if (input == 'd') {
                        system("cls");
                        printf("%s", map6m);
                        position = 7;
                        }
                        break;
                    }
                }

        }   while (1);

        printf("\ngame over");

   return 0;
}

