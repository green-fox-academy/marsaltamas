#include <stdio.h>
#include <limits.h>

void array_reverser (int arr[], int size);
void array_printer (int arr[], int size);
void array_reverser_with_sec_arr (int arr[], int size);

int main()
{
    //write a program which loads up fully a 50-sized integer array starting from 200 in descending order
    //but your array should contain elements which are divisible by 5 and 17
    //print out the array

    int my_array[50];
    int count = 0;

    for (int i = 200; i < INT_MAX; i++) {

        if (!(i % 85)) {
            my_array[count] = i;
            count++;
        }

        if (count == 50)
            break;
        }

    array_printer(my_array, sizeof(my_array) / sizeof(my_array[1]));

    array_reverser(my_array, sizeof(my_array) / sizeof(my_array[1]));

    array_printer(my_array, sizeof(my_array) / sizeof(my_array[1]));

    array_reverser_with_sec_arr(my_array, sizeof(my_array) / sizeof(my_array[1] ));

    array_printer(my_array, sizeof(my_array) / sizeof(my_array[1]));

    return 0;
}

void array_reverser (int arr[], int size)
{
    int temp = 0;
    for (int i = 0; i < size/2; i++) {
        temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
    printf("\nI am funct array_reverser. I have reversed the array\n");
}

void array_reverser_with_sec_arr (int arr[], int size)
{
    int temp_array[50];

    for (int i = size - 1; i >= 0; i--) {
        temp_array[i] = arr [size - i - 1];
    }

    for (int i = 0; i < size; i++) {
        arr[i] = temp_array[i];
    }
    printf("\nI am funct array_reverser_with_sec_arr. I have reversed the array\n");
}

void  array_printer (int arr[], int size)
{
    printf("\n\n------------------\n");
    printf("The array printed:\n\n");
    for (int i = 0; i < size; i++) {
        printf("Position #%d in my_array is %d\n", i, arr[i]);
    }
    printf("\nEnd of your array\n");
    printf("------------------\n");
}
