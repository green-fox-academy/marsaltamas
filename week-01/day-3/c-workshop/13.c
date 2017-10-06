#include <stdio.h>
#include <stdint.h>

int main() {

    uint8_t x = 0b11001100;
    uint8_t y = 0b01010101;
	uint8_t z;
	uint8_t a = 0b00000011;

	// Be z equal to the bitwise and of x and y

	z = x & y;

	printf("%s", "x bitwise and y test: ");
	printf("%c", z & 0b10000000 ? '1' : '0');
	printf("%c", z & 0b01000000 ? '1' : '0');
	printf("%c", z & 0b00100000 ? '1' : '0');
	printf("%c", z & 0b00010000 ? '1' : '0');
	printf("%c", z & 0b00001000 ? '1' : '0');
	printf("%c", z & 0b00000100 ? '1' : '0');
	printf("%c", z & 0b00000010 ? '1' : '0');
	printf("%c", z & 0b00000001 ? '1' : '0');

	// Check the result with printf

	printf("\n%i\n", z);

	// Be z equal to the bitwise or of x and y

	z = x % y;

	// Check the result with printf

	printf("%i\n", z);

    printf("%s", "a bitwise and test: ");
	printf("%c", a & 0b10000000 ? '1' : '0');
	printf("%c", a & 0b01000000 ? '1' : '0');
	printf("%c", a & 0b00100000 ? '1' : '0');
	printf("%c", a & 0b00010000 ? '1' : '0');
	printf("%c", a & 0b00001000 ? '1' : '0');
	printf("%c", a & 0b00000100 ? '1' : '0');
	printf("%c", a & 0b00000010 ? '1' : '0');
	printf("%c", a & 0b00000001 ? '1' : '0');

    return 0;
}
