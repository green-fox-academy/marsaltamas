#include <stdio.h>

typedef struct complex
{
    float real;
    float imag;
} complex;

//TODO: create 3 functions, which calculates the sum, subtraction and multiplication of a complex number.
// you can read about complex number's operations here: https://www.mathsisfun.com/numbers/complex-numbers.html
// for checking results: https://www.symbolab.com/solver/complex-numbers-calculator/

void printer(complex n);

complex addition(complex n1, complex n2);
complex substraction(complex n1, complex n2);
complex multibplication(complex n1, complex n2);

int main()
{
    complex n1, n2, sum, substracted, multiplicated;
    n1.real = 5;
    n1.imag = 7.2;

    n2.real = 6;
    n2.imag = 8.1;

    sum = addition(n1, n2);
    printer(sum);

    substracted = substraction(n1, n2);
    printer(substracted);

    multiplicated = multibplication(n1, n2);
    printer(multiplicated);

    return 0;
}
void printer(complex n)
{
    printf("Real part was %f\n", n.real);
    printf("Imaginary part was %f\n", n.imag);
    printf("=======================\n");
}
complex addition(complex n1, complex n2)
{
    complex sum;
    complex multiplicated;
    complex substracted;

    sum.real = n1.real + n2.real;
    sum.imag = n1.imag + n2.imag;

    return sum;
}

complex substraction(complex n1, complex n2)
{
    complex substracted;

    substracted.real = n1.real - n2.real;
    substracted.imag = n1.imag - n2.imag;

    return substracted;
}

complex multibplication(complex n1, complex n2)
{
    complex multiplicated;

    multiplicated.real = (n1.real * n2.real) - (n1.imag * n2.imag);
    multiplicated.imag = (n1.real * n2.imag) + (n1.imag * n2.real);

    return multiplicated;
}
