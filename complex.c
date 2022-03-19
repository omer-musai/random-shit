#include "complex.h"
#include <stdio.h>
#include <stdlib.h>
struct complex_t
{
    int re;
    int im;
};

Complex complexAdd(Complex a, Complex b)
{
    Complex c;
    c.re = (a.re + b.re);
    c.im = (a.im + b.im);
    return c;
}

int main()
{
    Complex a, b;
    printf("Enter first complex number: ");
    //scanf("%i %i", &a.re, &a.im);
    a.re = 3;
    a.im = 3;

    printf("Enter second complex number: ");
    //scanf("%i %i", &b.re, &b.im);
    b.re = 1;
    b.im = 1;

    Complex c = complexAdd(a, b);
    int m = c.re;
    int n = c.im;

    printf("the result is: real: %i imaginary: %i", m, n);
    
}