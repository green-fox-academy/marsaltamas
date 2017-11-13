/*
 * Check out the following code.
 * Read it for Yourself, decode what is happening here.
 *
 */

#include <stdio.h>

int main(){
    int integers[] = {12,23,34,45,56,67,78,89,90};
    int* apointer = integers;
    printf("address\t\tvalue\n%p\t%d\n",apointer, *apointer);
    apointer+=3;
    printf("%p\t%d\n",apointer, *apointer);
    printf("-------------------------------\n\n");

    // ptr - ptr2 is not 4, but 1 unit
    for(int* ptr = integers; ptr-integers < 9; ptr++){
        printf("%d\t%d\n", ptr, *ptr);
        printf("%d\t%d\n", integers, *integers);
    }
    return 0;
}
