#include <stdio.h>
#include <assert.h>

void minmaxmean(double x[], int n)
{
    int i;
    double min = x[0];
    double max = x[0];
    double s = 0;
    for (i = 0; i < n; i++)
    {
        if (x[i] < min)
        {
            min = x[i];
        }
        if (x[i] > max)
        {
            max = x[i];
        }
        s = s + x[i];
    }
    double mean = s / n;
    printf("min= %f\n", min);
    printf("max= %f\n", max);
    printf("mean= %f\n", mean);
}

void main()
{
    int n,i;
    printf("Enter integer n= ");
    scanf("%d", &n);
    assert(n >= 1);
    double x[n];
for (i = 0; i < n; i++)
    {
        printf(" x[%d]= ",i+1);
        scanf("%lf", &x[i]);
    }
    minmaxmean(x, n);
}

