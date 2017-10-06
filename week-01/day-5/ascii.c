#include <stdio.h>
#include <stdlib.h>

//create a program to print ASCII values of all characters.
/*your outpu should be something like this:
ASCII value of character 8 = 56
ASCII value of character 9 = 57
ASCII value of character : = 58
ASCII value of character ; = 59
ASCII value of character < = 60
ASCII value of character = = 61
ASCII value of character > = 62
ASCII value of character ? = 63
ASCII value of character @ = 64
ASCII value of character A = 65
ASCII value of character B = 66
*/


int main()
{

    for (int i = 0; i < 256; i++) {

        switch (i) {
        case 7 :
            printf("ASCII value of character \"Bell\" = %d\n", i, i);
            break;
        case 8 :
            printf("ASCII value of character \"Backspace\" = %d\n", i, i);
            break;
        case 9 :
            printf("ASCII value of character \"Horizontal tab\" = %d\n", i, i);
            break;
        case 10 :
            printf("ASCII value of character \"Line feed\" = %d\n", i, i);
            break;
        case 13 :
            printf("ASCII value of character \"Carriage return\" = %d\n", i, i);
            break;
        default :
            printf("ASCII value of character %c = %d\n", i, i);
        }

    }

	return 0;
}
