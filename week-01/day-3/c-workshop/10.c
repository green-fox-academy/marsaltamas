#include <stdio.h>

int main() {
	double j1 = 10;
	double j2 = 3;
	// tell if j1 is higher than j2 squared and smaller than j2 cubed

	printf("j1:%.2f\nj2:%.2f\nj2squared:%.2f\nj2cubed:%.2f\n", j1, j2, pow(j2, 2), j2 * j2 * j2);

	if ((j1 > pow(j2, 2)) && j1 < pow(j2, 3)) {

        printf("j1 is higher than j2 squared and smaller than j2 cubed.");

    }

	return 0;
}
