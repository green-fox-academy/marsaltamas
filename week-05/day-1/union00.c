/*
 * Use the union type we've defined below to write out the integer array nums
 * as if it was an array of characters;
 * Use pointer arithmethircs to iterate over the array with the ptr.
 */
#include <stdio.h>

typedef union {
    int* asInt;
    char* asChar;
} ptr;


int main(){
    int nums[] = { 1952540759, 544171040, 1685221239, 1869573152, 1768693867, 1847616875, 1700949365, 4158322};

    ptr p;

    for (p.asInt = nums; p.asInt - nums < sizeof(nums) / sizeof(nums[0]); p.asInt++) {
        printf("nums[%d]: %d\n", p.asInt - nums, *p.asInt);
    }

    for (p.asChar = (char*) nums; p.asChar - (char*) nums < sizeof(nums); p.asChar++) {
        printf("nums[%d]: %c\n", p.asChar - (char*) nums, *p.asChar);
    }

    return 0;
}
