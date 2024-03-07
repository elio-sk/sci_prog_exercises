#include <stdio.h>

double secant(double (*f)(double), double x0, double x1, double eps)
{

    double x2;
    double f0 = f(x0);
    double f1 = f(x1);

    while (fabs(f(x1)- f(x0)) > eps)
    {   
        x2 = x1 - f1 * (x1 - x0) / (f1 - f0);
        x0 = x1;
        x1 = x2;
        f0 = f1;
        f1 = f(x1);

        if (fabs(x2) <= eps)
        {
            if (fabs(f(x2)) <= eps && fabs(x2 - x1) <= eps)
            {
                printf("The method has converged");
                return x1;
            }
        }

        else if (fabs(f(x2)) <= eps && fabs(x2 - x1) <= eps*fabs(x2))
        {
            printf("The method has converged");
            return x1;
        }
    }

    return x1;
}



double f(double x)
{
    return x*x-2;
}


int main()
    {
    double x0, x1, eps;
    double (*ff)(double);
    ff = &f;
    x0 = 1;
    x1 = 2;
    eps = 0.01;
    printf("Approximation of sqrt(2) is %lf\n", secant(f, x0, x1, eps));
    return 0;
    }
