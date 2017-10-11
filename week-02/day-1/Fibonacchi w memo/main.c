# include <stdlib.h>
# include <stdio.h>

void fibonacchi_w_memo(int);

int main ()
{
    fibonacchi_w_memo(40);

    return 0;
}

void fibonacchi_w_memo(int to_element)
{
    int n = 1;
    int n_min_1 =0;
    int temp = 0;

    for (int i = 1; i < to_element; i++) {
        temp = n;
        n = n + n_min_1;
        printf("Element #%d of the Fibonacchi series is %d.\n", i, n);
        n_min_1 = temp;
    }

    return n;
}
