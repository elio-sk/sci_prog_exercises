#include <stdio.h>
#include <stdlib.h>

void unique(double *x, int *n) {
    int i, j,k;
for (i = 0; i < *n; i++)
	{
		for(j = i + 1; j < *n; j++)
		{
    		if(x[i] == x[j])
    		{
    			for(k = j; k < *n; k++)
    			{
    				x[k] = x[k + 1];
				}
				(*n)--;
				j--;
			}
		}
	}
}

void bubbleSort(double *x, int n) {
    int i, j; double temp;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (x[j] > x[j + 1]) {
            	temp=x[j];
            	x[j]=x[j+1];
            	x[j+1]=temp;
                //swap(&x[j], &x[j + 1]);
            }
        }
    }
}



void main(){
int n; int i=0;
printf("Enter the number of elements: ");
scanf("%d", &n);
double *x = malloc(n * sizeof(double));
for ( i = 0; i < n; i++) {
    printf("Enter element %d: ", i + 1);
    scanf("%lf", &x[i]);
}
printf("Before sorting: ");
for ( i = 0; i < n; i++) {
    printf("%f ", x[i]);
}

unique(x,&n);
x=realloc(x,n*sizeof(double));


printf("\n");
for ( i = 0; i < n; i++) {
    printf("%f ", x[i]);
}

bubbleSort(x,n);



printf("\nAfter arranging: ");
for ( i = 0; i < n; i++) {
    printf("%f ", x[i]);
}

}
