#include <stdio.h>
#include <assert.h>
#include <math.h>

//Newton-Rhapson's method to find root of x^3-a=0 

double cubeRoot(double a, double tol){
    double x = a/2, xx=0; //initial guess x0
    while(fabs(xx - x) > tol){
        xx=x;
        x=x-(x*x*x -a)/(3.0*x*x);
    }
    return x;
}

void main()
{
    double tol = 0.001;
    double x = -27.0;
    double result = cubeRoot(x, tol);
    printf("Program: %f\n", result);
    printf("cbrt: %f\n\n", cbrt(x));

}

//Test examples: take a perfect cube positive, also negative
