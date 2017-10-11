# include <stdlib.h>
# include <stdio.h>

int look_up [100];

int fibonacchi_w_memo(int);

int fibonacchi_w_memo(int n)
{
     if (n == 0)
        return 1;
    else if (n == 1)
        return 1;
    else if(look_up[n] == 0)
                look_up[n] = fibonacchi_w_memo(n - 1) + fibonacchi_w_memo(n - 2);

    return look_up[n];
}

int main ()
{
    for (int i = 0; i < 15; i++) {
    printf("%d   ", fibonacchi_w_memo(i));
    }

    printf("\n");

    for (int i = 0; i < 15; i++) {
    printf("%d   ", look_up [i]);
    }

}
