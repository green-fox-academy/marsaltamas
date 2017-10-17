#include <stdio.h>
#include <math.h>

void int_to_bin_digit(int in)
{
	int mask = (int) pow(2,(log10(in) / log10(2)) + 4);
	int i;
	int result = 0;

	if (in == 0) {
         printf("%d", 0);
	} else {

	    int space = 0;

        for (i = mask; i >= 1; i/=2) {
            result = (in & mask) ? 1 : 0;
            printf("%d", result);
            mask = mask >> 1;

            space++;

            if (space % 4 == 0) {
                printf(" ");
            }
        }
	}
}

int main()
{
	int_to_bin_digit(8);
	return 0;
}
