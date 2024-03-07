#include <stdio.h>
#include <assert.h>

void swap(double *x, double *y)
{
    double tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

void print_vector(double *x, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%f ", x[i]);
	}
	printf("\n");
}


void quickSort(double *x, int n)
{
	if (n <= 1)
	{
		return;
	}

	double pivot = x[n / 2]; 
	int k = 0; 
	int j = n - 1; 

	while (k <= j)
	{
		while (x[k] < pivot)
		{
			k++;
		}
		while (x[j] > pivot)
		{
			j--;
		}
		if (k <= j)
		{
			swap(&x[k], &x[j]);
			k++; 
			j--; 
		}
	}

	quickSort(x, j + 1);
	quickSort(x + k, n - k);
}



void main(void)
{
	int n = 9;
	double x[] = {4,3,7,9,4,3,1,7,9};
	printf("Unsorted vector   ");
	print_vector(x, n);
	quickSort(x, n);
	printf("Sorted vector ");
	print_vector(x, n);

}
