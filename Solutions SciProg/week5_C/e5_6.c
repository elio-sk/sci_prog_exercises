#include <stdio.h>
#include <assert.h>


void Pascal(int n)
{
    int i, j;
    for(i=1; i<=n; i++){
    int coeff=1;
    for(j=1; j<=i; j++)
    {
      printf("%d ",coeff);
      coeff = coeff * (i-j)/j;
    }
    printf("\n");	
	}
}

void main()
{
    int n;
    printf("Enter integer n: ");
    scanf("%d", &n);
    assert(n >= 1);
    printf("Pascal triangle:\n");
    Pascal(n);
}

