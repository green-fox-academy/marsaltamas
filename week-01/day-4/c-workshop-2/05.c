#include <stdio.h>

int main() {
	// print the even numbers till 20

	int a = 1;

	while (a < 20) {
        if (!(a % 2))
        printf("while loop: a = %d is even.\n", a);

        a++;
    }

    a = 1;

    printf("\n\n");

    do {
        if (!(a%2))
        printf("do-while loop: a = %d is even.\n", a);

        a++;
    }while (a < 20);

    printf("\n\n");

	for (int i = 1; i < 21; i++){


        if (!(i%2))
        printf("for loop: i = %d is even.\n", i);

    }

    return 0;


}
