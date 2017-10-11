#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int give_me_limit(void);
void array_printer(int arr[][1], int size, int step);

int main()
{
    // setting up limit
    int size = give_me_limit();
    static int array[10000000][1];

    // loding array up to given limit
    for (int i = 0; i < size; i++) {
        array[i][1] = 1;
    }



    array_printer(array, size, 1);


}

// requests the user to input the upper limit up to which he wants to find primes
int give_me_limit (void)
{
    int size = 0;

    do {
        printf("Please enter a limit up to which you want to list prime numbers (between 1 and 10 000 000): ");
        scanf("%d", &size);
        printf("You entered %d.\n", size);
    } while (size < 1 || size > 10000000);

    return size;
}
// prints array up to given size at the rate of give steps
void array_printer (int arr[][1], int size, int step)
{

    for (int i = 0; i < size; i = i + step) {

        printf("Array element at pos #%d is %d.\n", i, arr[i][1]);
    }

}
