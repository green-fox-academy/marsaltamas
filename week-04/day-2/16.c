#include <stdio.h>

int assort_odd_elements(int *array, int size);
void printer(int *array, int size);

int main(void)
{
	int num_array[] = {8, 7, 10, 9, 77, 40, 80, 55, 20, 3, 81, 79, 66, 88, 70};

    //TODO: write a function which filters out the odd elements of an integer array
    //do it in the original array
    //your return value should be the real size of the filtered array
    //print out the filtered array's elements

    printer(num_array, assort_odd_elements(num_array, sizeof(num_array) / sizeof(num_array[0])));

    return 0;
}

void printer(int *array, int size)
{
    for (int i = 0; i < size; i++) {

        printf("array[%d] is %d.\n", i, array[i]);
    }
}

int assort_odd_elements(int *array, int size)
{

    for (int i = 0; i < size; i++) {
        if (array[i] % 2) {
            for (int j = i; j < size; j++) {
                array[j] = array[j + 1];
            }
            size--;
            i--;
        }
    }

    return size;
}
