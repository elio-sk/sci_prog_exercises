#include <stdio.h>

void swap(double *a, double *b) {
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

void main()
{
    double a = 1.0;
    double b = 2.0;
    swap(&a, &b);
    printf("a=%f \n  b=%f\n", a, b);
}
