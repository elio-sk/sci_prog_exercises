#include <stdio.h>
#include <assert.h>
#include <math.h>


double geometricMean(double *x, int n)
{
    int i=0;
    double p = 1.0;
    for (i = 0; i < n; i++)
    {
        p = p * x[i];
    }
    return pow(p,1.0/n);
}

void main()
{
    int n; 
    printf("Input n=");
    scanf("%d",&n);
    assert(n >= 1);

    int i = 0; double x[n];
    for (i = 0; i < n; i = i + 1)
    {
    	printf("\n x[%d]=",i);
        scanf("%lf", &x[i]);
    }

    double gm = geometricMean(x, n);
    printf("\nGeometric Mean=%f\n", gm);

}

//Appropriate tests vectors that have the same entry n-times
