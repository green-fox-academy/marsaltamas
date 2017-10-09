# include <stdlib.h>

int factorial (int n);
int factorial_rec (int n);


int main()
{
    factorial(6);
    printf("factorial of %d using recursion is %d", 6, factorial_rec(6));

    return 0;
}

int factorial(int n)
{
    int result = 1;

    for (int i = 1; i <= n; i++) {
        result = result * i;
    }

    printf("factorial of n is %d\n", result);

    return result;
}
int factorial_rec(int n)
{
    if (n == 1)
        return 1;
    else
        return n*factorial_rec(n-1);
}


