#include <stdio.h>
#include <stdint.h>

int main() {
	uint8_t ad = 6;
	int a = 0;

	// print the numbers till ad from 0

	while (a <= ad){
        printf("Running while loop a = %d.\n", a);
        a++;
    }

    a = 0;

    printf("\n\n");

    do {
        printf("Running do-while loop a = %d.\n", a);
        a++;
    }while (a <= ad);

     printf("\n\n");

     for (int i = 0; i <= ad; i++){
        printf("Running for loop a = %d.\n", i);
     }


	return 0;
}
