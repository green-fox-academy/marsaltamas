#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int give_me_limit(void);
void array_printer(int arr[], int size, int step);

int main()
{

    int size = give_me_limit();
    static int array[10000000];


    for (int i = 0; i < size; i++) {
        array[i] = i;
    }

    array_printer(array, size, 1000);


}

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

void array_printer (int arr[], int size, int step)
{

    for (int i = 0; i < size; i = i + step) {

        printf("Array element at pos #%d is %d.\n", i, arr[i]);
    }

}
