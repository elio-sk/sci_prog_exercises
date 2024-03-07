#include <stdio.h>
#include <assert.h>

//for strange reason works only with vectors with float entries but not doubles

void bubbleSort( int n,float x[n])
{
    int i, j;
    float a;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n -i - 1; j++)
        {
            if (x[j] > x[j + 1])
            {
                a = x[j];
                x[j] = x[j + 1];
                x[j + 1] = a;
                // 1 swap
            }
        }
    }

}


void main()
{
    int i,j,n; float x[n];
    printf("Enter integer n= ");
    scanf("%d", &n);
    assert(n >=1);
    
    for (i = 0; i <n; i++)
    {
        printf("x[%d]= ", i+1);
        scanf("%f",&x[i]);
    }
    for (j = 0; j <n; j++)
    {
        printf("%f\n ", x[j]);
    }
    printf("\n\n");
    bubbleSort(n,x);
    for (i = 0; i <n; i++)
    {
        printf("%f   ", x[i]);
    }
}
