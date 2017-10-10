#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[20];
    int freq[20];
    int real_arr_size = 0;

    // TODO: write a program which asks for a number,
    // that will be the real size of the array (20 elements are allocated, that's the maximum size)

    printf("Please enter a size for an array between 1 and 20: ");
    scanf("%d", &real_arr_size);

    printf("\nReal arr size is %d\n\n", real_arr_size);

    // Then load up the array with integer values

    for (int i = 0; i < real_arr_size; i++) {
        printf("Please enter an element for position %d.: ", i);
        scanf("%d", &arr[i]);
    }

    puts("\nThe inputed array is:");

    for (int i = 0; i < real_arr_size; i++) {
        printf("Position %d.: %d\n", i, arr[i]);
    }

    puts("\n");

    // Finally print all unique elements in array

    int flag = 0;

    for (int i = 0; i < real_arr_size; i++) {

        for (int y = 0; y < real_arr_size; y++) {

            if (arr[i] == arr[y])
                flag++;

                if(flag > 1)
                    break;
        }

        if (flag < 2) {
            printf("Position %d. = %d is unique in the array.\n", i, arr[i]);
        }

        flag = 0;
    }


    return 0;
}
