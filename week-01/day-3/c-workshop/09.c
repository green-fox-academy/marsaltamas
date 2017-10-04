#include <stdio.h>

int main() {
	int i = 53625;;
	// tell if it has 11 as a divisor

	printf("i= %d / 11 = %d\n", i, i/11);
	printf("i= %d mod 11 = %d\n", i, i%11);

	if((i%11)==0){
        printf("%d has 11 as a divisor", i);
	}
	else{
        printf("%d does not have 11 as a divisor", i);
	}


	return 0;
}
