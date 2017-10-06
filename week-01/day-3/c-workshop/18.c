#include <stdio.h>
#include <stdint.h>

int main() {

	uint16_t number = 253;
	uint8_t eigth_bit_max = 0b11111111;

	printf("eight_bit_max is %d\n", eigth_bit_max);

	if (number > eigth_bit_max)
        printf("longer than 8bits");
    else
        printf("ok");

	// if number can't be represented with 8bits
	// print 'longer than 8bits' otherwise print 'ok'
	return 0;
}
