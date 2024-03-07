#include <stdio.h>
#include <assert.h>
char structure(int n, double A[n][n] )
{
    int i,j,lt,ut;
    lt=1;
    ut=1;
    // In the worst case we have 4 comparisons and 1 assignment
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i < j)
            {
                if (A[i][j] != 0)
                {
                    lt=0;
                    break;
                }
            }
            else if (i > j)
            {
                if (A[i][j] != 0)
                {
                    ut=0;
                    break;
                }
            }

        }
        
    }
   // 3 conditional statements
    if (ut==1 && lt==1)
    {
        return 'd';
    }
    else if (lt==1)
    {
        return 'l';
    }
    else if (ut==1)
    {
        return 'u';
    }
    else
    {
        return 'f';
    }
 

    // Complexity=5n^2 +3 = O(n^2)
}

void main()
{
	int i,j,n;
    printf("Enter integer n= ");
    scanf("%d", &n);
    assert(n >= 1);
    double A[n][n];
    for( j=0; j<n; j++){
    	for( i=0; i<n; i++){
    		printf("A[%d][%d]=",i+1,j+1);
    		scanf("%lf",&A[i][j]);
		}
	}
	
	 printf("Matrix A has %c\ structure.", structure(n,A));
	
}
