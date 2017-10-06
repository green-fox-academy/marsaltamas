#include <stdio.h>
#include <stdint.h>

int main() {
    uint8_t a = 60;
    uint8_t b = 0b00111100;
    uint8_t c = 0x3C;
    uint8_t d = 0x3c;

    printf("------------------\n", d);
    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", c);
    printf("%d\n", d);
    printf("------------------\n", d);

    // Try with %x

    // Multiply a by 2
    a = a * 2;

    // Shift left b by 1
    b = b << 1;

    // Check their values
    printf("%d\n", a);
    printf("%d\n", b);
    printf("%8x\n", c);
    printf("%08x\n", d);
    printf("------------------\n", d);

    return 0;
}
