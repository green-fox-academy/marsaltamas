#include <stdio.h>
#include <stdint.h>

struct Computer {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
};

void print_struct(struct Computer Computer);

int main()
{
    struct Computer computer = {3.2, 8, 32};

    //TODO: Change the bits to 64

    //TODO: print out the structure members

    print_struct(computer);

    computer.bits = 64;

    print_struct(computer);

    return 0;
}

void print_struct(struct Computer computer)
{
    printf("speed: %.2f\n", computer.cpu_speed_GHz);
    printf("ram size %.d\n", computer.ram_size_GB);
    printf("bits: %d\n", computer.bits);
}
