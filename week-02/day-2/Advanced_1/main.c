#include <stdio.h>
#include <stdlib.h>


int main()
{
    int arr[50];

    // TODO: write a program wich asks for a number, that will be the real size of the array
    // (50 elements are allocated, that's the maximum size)
    // Then load up the array with integer values
	// print out the array

    int arr_max = 0;

    printf("Enter a number between 1 and 50 to set the size of the array to fill:  ");
    scanf("%d", &arr_max);

    for (int i = 0; i < arr_max; i++) {

        arr[i] = rand() % 100;
    }

    puts("\nThe filled array: ");

    for (int i = 0; i < arr_max; i++) {
        printf("position %d.: ", i);
        printf("%d \n", arr[i]);
    }

    puts("");

    // Then ask for a number, that will be the position, where you want the element to be deleted
    // handle the problem when trying to delete from invalid positions (e.g. negative number)
    // print out the the array after the deleting

    int to_delete = -1;

    while (to_delete < 0 || to_delete > arr_max - 1) {

        printf("Enter a position where you want the array content to be deleted between 0 and %d:  ", arr_max - 1);
        scanf("%d", &to_delete);

        if (to_delete < 0 || to_delete >= arr_max)
            printf("The entered position %d is out of bounds!\n", to_delete);
    }

    printf("\nPosition to delete: %d\n", to_delete);

    for (int i = to_delete; i < arr_max -1; i++) {

        arr[i] = arr [i + 1];
    }

    puts("\nThe array after removing the requested position: ");

     for (int i = 0; i < arr_max - 1; i++) {
         printf("position %d.: ", i);
         printf("%d \n", arr[i]);
    }

    return 0;
}
