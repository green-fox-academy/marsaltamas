#include <stdio.h>

int main() {
	int i = 53625;
	// tell if it has 11 as a divisor

	printf("i= %d / 11 = %d\n", i, i/11);
	printf("i= %d %c 11 = %d\n", i, 37, i%11);

	if(!(i%11))
        printf("%d has 11 as a divisor", i);
	else
        printf("%d does not have 11 as a divisor", i);



	return 0;
}
