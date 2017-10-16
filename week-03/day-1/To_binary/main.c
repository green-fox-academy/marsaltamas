#include <stdio.h>
#include <math.h>

void int_to_bin_digit(int in)
{
	int mask = (int) pow(2,(log10(in) / log10(2)));
	int i;
	int result = 0;

	if (in == 0) {
         printf("%d", 0);
	} else {
        for (i = mask; i > 0; i/=2) {
            result = (in & mask) ? 1 : 0;
            printf("%d", result);
            mask = mask >> 1;
        }
	}
}

int main()
{
	int_to_bin_digit(72);
	return 0;
}
