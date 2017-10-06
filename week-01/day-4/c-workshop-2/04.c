#include <stdio.h>
#include <stdint.h>

int main() {
	uint8_t ae = 4;
	int a = 0;
	// print "yeeeeeeeey" ae times

	while (a < ae) {
        printf("while loop says: yeeeeeeeey\n");
        a++;
    }

    a = 0;

    printf("\n\n");

    do {
         printf("do- while loop says: yeeeeeeeey\n");
        a++;
    }while (a < ae);

    printf("\n\n");

    for (int i = 0; i < ae; i++) {
        printf("for loop says: yeeeeeeeey\n");
        a++;
    }






	return 0;
}
