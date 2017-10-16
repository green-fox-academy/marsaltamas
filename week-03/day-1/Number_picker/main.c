#include <stdio.h>
#include <stdint.h>
// there was a typo in the printf statement, and the from variable was over the int size
// therefore loop counter was initialized over the to limit.

void printf_numbers(int from, int to)
{
	for (int i = from; i < to; i++)
		printf("%d\n", i);
}

int main()
{
	printf_numbers(2147483600, 2147483647);
	return 0;
}
