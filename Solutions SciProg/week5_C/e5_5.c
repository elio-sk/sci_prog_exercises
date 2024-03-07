#include <stdio.h>
#include <assert.h>
#include <math.h>

double partialSum(int n){
    double S = 0;
    int k;
    for (k = 0; k < n; k++)
    {
    	S=S+4*pow(-1,k)/(2*k+1);
    }
    return S;
}

int main() {
    int n;
    printf("Enter integer n: ");
    scanf("%d", &n);
    assert(n >= 0);
    printf("Partial sum: %f\n", partialSum(n));
}
