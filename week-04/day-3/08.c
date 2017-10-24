#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

    //TODO: make a custom type from union and nested structs. this type should be 8 bit wide.
	//you should be able to assign values:
	// - each bits
	// - upper 3 bits and lower 5 bits
	// - the whole 8-bit memory

struct whole {
    uint8_t a;
};

struct first {
    uint8_t a : 1;
};

struct upper3 {
    uint8_t upper : 3;
};

struct lower5 {
    uint8_t lower : 5;
};

struct upper_lower {
    struct upper3 _upper3;
    struct lower5 _lower5;
};

typedef union {
    struct whole _whole;
    struct first _1st;
    struct upper_lower _upper_lower;
} my_memory;

int main()
{
    my_memory mem;
    char upper[9];
    char lower[9];

    mem._whole.a = 0b11100010;
    printf("The whole memory: %d\n", mem._whole.a);

    mem._upper_lower._lower5.lower = 0b10100;
    mem._upper_lower._upper3.upper = 0b101;

    printf("upper 3 and lower 5 is %s:%s\n", itoa(mem._upper_lower._upper3.upper, upper, 2), itoa(mem._upper_lower._lower5.lower, lower, 2));

    mem._1st.a = 1;
    printf("The first bit of mem %d\n", mem._1st.a);

    printf("size of my_memory %d\n", sizeof(my_memory));

    return 0;
}
